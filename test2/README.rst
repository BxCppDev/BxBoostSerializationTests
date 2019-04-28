===================================
BxBoostSerializationTests - test #2
===================================

:author: F.Mauger

The  aim of  this test  is to  implement a  hierarchy of  serializable
classes, inheriting an unique base abstract class, and publish them in
a shared library.   We use a technique which  forces the instantiation
of the  template code specific to  Boost I/O XML and  text archives to
make sure  all classes in  the shared  library are registered  for all
supported  archive   types.   Objects   of  these  classes   are  thus
(de)serializable using  pointers through  their base class,  thanks to
the Boost/Serialization class export/registration mecanism.

The   test  also   investigates  how   we  can   implement  additional
serializable and registered classes from client programs.

Contents:

* the ``lib1`` shared library contains the following classes:

  - ``lib1::base`` : abstract base serializable class
  - ``lib1::class1`` : serializable class inheriting ``lib1::base``
  - ``lib1::class2`` : serializable class inheriting ``lib1::base``
  - ``lib1::class3`` : serializable class inheriting/extending ``lib1::class1``

  The classes  are exported/registered directly in  the shared library
  compilation unit using dedicated macros.
    
* ``test2.cxx`` : links to the ``lib1`` shared library

  It  serializes in  a string  buffer a  set of  3 shared  pointers on
  ``lib1::base``  class,  using  instances  of  the  ``lib1::class1``,
  ``lib1::class2`` and  ``lib1::class3``. The  buffer is then  used to
  deserialize the 3 objects.

* ``test2b.cxx`` : links to the ``lib1`` shared library

  Same as  ``test2.cxx`` but implements a  new ``class4`` serializable
  class  which  is  exported/registered   directly  from  the  program
  compilation unit.
  
  The program serializes in a string buffer a set of 4 shared pointers
  on ``lib1::base``  class, using  instances of  the ``lib1::class1``,
  ``lib1::class2``,  ``lib1::class3`` and  ``class4``.  The buffer  is
  then used to deserialize the 4 objects.

* ``test2c.cxx`` :

  Same as  ``test2b.cxx`` but  ``class4`` and  its export/registration
  code is  first built in  the ``libmain`` shared library  which links
  itself  to the  ``lib1``  shared library.  ``test2c``  links to  the
  ``libmain`` shared library


..
