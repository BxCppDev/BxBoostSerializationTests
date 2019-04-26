==================================
BxBoostSerializationTests
==================================


This projects contains some program which explicitely test
functionalities from the Boost/Serialization library.



* ``test1`` :

  This case is related to :

  - ``https://github.com/boostorg/serialization/issues/82``
  - ``https://stackoverflow.com/questions/2205404/how-to-flush-file-buffers-when-using-boostserialization``
    
  It illustrates a difference between Boost 1.65.1 and 1.68 while using
  XML I/O archives and proposes a technique to avoid the problem.
