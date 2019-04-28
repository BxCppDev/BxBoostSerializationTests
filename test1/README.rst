===================================
BxBoostSerializationTests - test #1
===================================

:author: F.Mauger

In this section, we explore some aspects of the  following issues:

- https://github.com/boostorg/serialization/issues/82
- https://github.com/boostorg/serialization/issues/109

Tested Boost versions: 1.65.1 (from system Ubuntu 18.04)
and 1.68.0 (manually installed).


Contents
========
  
* ``test1.cxx`` :
	 
  The  ``test1.cxx`` program  aims to  serialize, then  deserialize, a
  vector of ints  using the XML archive format and  a string buffer as
  the storage  medium. It is shown  how the way the  string buffer and
  the XML  archive objects are  instantiated (in terms  of declaration
  order and scope)  influences the behaviour of the  code and possibly
  breaks it, depending on the Boost version.
  
  Three functions are implemented:
  
  * ``f_broken`` serializes  a vector of  ints in a string  buffer but
    breaks the  XML formatting due  to uncorrectly scoped  XML archive
    with respect to the working string buffer.
  * ``f`` serializes a vector of ints  in a string buffer with correct
    XML formatting  due to proper  scoped XML archive with  respect to
    the working string buffer.
  * ``g``  attempts to  deserialize a  vector  of ints  from a  string
    buffer with  XML formatting. It  possibly fails, depending  on the
    Boost version, in the case of a broken format of the input working
    string buffer.



* ``test1a.cxx``   :  This  is a fixed version of the   program  provided   by
  ``steronydh``                                                  at
  https://github.com/boostorg/serialization/issues/82


* ``test1b.cxx``   :  This   reproduces   the   program  provided   by
  ``tsondergaard``                                                  at
  https://github.com/boostorg/serialization/issues/109

  The  issue is  different, while  related, to  the one  shown in  the
  ``test1.cxx`` program.

  From Boost 1.66, this code breaks with error::

  .. code::
     
     terminate called after throwing an instance of 'boost::archive::archive_exception'
       what():  input stream error-Success
     Aborted (core dumped)
  ..

  My understanding of the issue is the following:

  When  the serialization  library  attempts to  read the  *not_there*
  instance from  the input XML archive,  it fails as expected  but the
  underlying input  stream is let  at an arbitrary position  after the
  failure. I  expect this  new position  matches the  end of  the next
  ``<xxx>some  contents</xxx>``  tag  which corresponds  here  to  the
  ``</boost_serialization>`` tag.  The exception is thrown as expected
  and, at the end of the  scope, the archive destructor is invoked and
  tries to  read the  final ``</boost_serialization>`` tag,  which has
  already  been skipped  in the  stream.   Thus, the  position of  the
  stream after the failed attempt does not permit to read properly the
  final tag.

  One may  think this behaviour is  normal and sane and  consider that
  the behaviour before Boost 1.66 was buggy. If one tries to read some
  possibly missing  records from  an archive, we  must add  the proper
  code to handle  this specific use case.  The  exception mechanism is
  only to signal a possible problem (i.e. a missing tag), not to solve
  the  problem. A  specific  error  handler must  be  provided by  the
  programmer.  The library  probably cannot  address all  the possible
  issues by itself.  
  
  The ``test1c.cxx``  program below  proposes a strategy  to correctly
  address the problem in this specific case.

* ``test1c.cxx`` : Same as ``test1b.cxx``

  The technique used here consists in saving the position of the input
  stream just before a possible failure in order to be able to restore
  a position of this input stream in case of error. This makes finally
  possible to  read the final ``</boost_serialization>``  tag when the
  archive's destructor is invoked.

  This approach  works but  look at  the ``test1d.cxx``  program which
  illustrates the kind of nightmare we face when we try to deserialize
  a more complex set of values.
 
* ``test1d.cxx`` : Based on ``test1c.cxx``

  Here a ``b``  value is randomly inserted in the  archive between the
  ``a`` and ``c`` values.  At deserialization, the code tries to guess
  if ``b``  is present.  When  it is  present, the code  runs properly
  both for 1.65 and 1.68.  If ``b`` was not serialized in the archive,
  the ``c``  value is parsed  and assigned to  ``b`` and ``b``  is not
  detected to be missing.  One important point is that the XML archive
  does not check the tags  associated to serialized values through the
  name-value pair  object. Indeed, we  have used here  different names
  for  deserialization with  respect  to  serialization.  Finally,  an
  error is detected  while trying to deserialize ``c``  because it has
  already been extracted and loaded  from the stream and thus assigned
  to ``b``.   We are  thus forced to  use an ugly  fix to  restore the
  proper ``c`` value and terminate the archive without error.
  This illustrates a situation which is not satisfactory at all.

  Should we incriminate  the Boost Serialization library  ?  I believe
  no.

  The fact  that the  names of  the XML tags  are not  checked clearly
  prevents us to detect the missing ``b`` issue and install an adapted
  error handler.  On  the other hand it may be  an interesting feature
  if  we want  to  deserialize  data from  a  XML  archive using  some
  specific names of our choice which  we prefer to the original set of
  different names used by the original serialization code.

  By   the   way,   I   don't    understand   the   purpose   of   the
  ``boost::archive::no_xml_tag_checking``  initialization  flag, as  I
  cannot see any XML tag checking when using the XML archive's default
  constructor.
  
  At a more  fundamental level and in my humble  opinion, the use case
  illustrated  by the  original  ``test1b.cxx`` program  in issue  109
  consists is  a bad programming  practise.  I believe one  should use
  the  Boost archive  with well  defined and  controlled data  models.
  Implementing  serialization  code  using  such  a  trial  and  error
  technique is inappropriate and prone to problems. The ``test1e.cxx``
  program proposes a possible approach to workaround the issue 109.
  
* ``test1e.cxx`` :  Based on ``test1d.cxx``  but solved the  issue for
  Boost 1.68 using instances of ``boost::optional<int>``. No trick or special
  error handling code is necessary.

  
 
  



  
  

  
  
  
