===================================
BxBoostSerializationTests - test #1
===================================

The ``test1.cxx`` program aims to serialize, then deserialize,
a vector of ints using the XML archive format and a string buffer
as the storage medium. It is shown how the way the string buffer
and the XML archive objects are instantiated (in terme of
declaration order and scope) influences the behaviour of the code
and possibly breaks it depending on the Boost version.

Three functions are provided:

* ``f_broken`` serializes a vector of ints in a string buffer
  but breaks the XML formatting due to uncorrectly scoped XML archive
  with respect to the working string buffer.
* ``f`` serializes a vector of ints in a string buffer
  with correct XML formatting due to proper scoped XML archive
  with respect to the working string buffer.
* ``g`` attempts to deserialize a vector of ints from a string buffer
  with XML formatting, possibly fails depending on the Boost version
  in case of a broken format of the working string buffer.

