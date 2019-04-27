==================================
BxBoostSerializationTests
==================================


This   projects  contains   some   programs   which  explicitely   test
functionalities from the Boost/Serialization  library.  The goal is to
help to investigate  and solve issues when new versions  of both Boost
and compiler are released.

The target operating system is Ubuntu Linux using the GCC compiler but
the tests can be adapted to other situations.


* ``test1/`` :  This case is related to :

  - ``https://github.com/boostorg/serialization/issues/82``
  - ``https://stackoverflow.com/questions/2205404/how-to-flush-file-buffers-when-using-boostserialization``
    
  It illustrates a difference between Boost 1.65.1 and 1.68 while using
  XML I/O archives and proposes a technique to avoid the problem.

 
* ``test2/`` :  Implementing serializable classes from
  a shared library.

* ``tools/`` : directory with quick-start build scripts for my own system (Ubuntu 18.04)

 
