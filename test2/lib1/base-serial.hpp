#ifndef LIB1_BASE_SERIAL_HPP
#define LIB1_BASE_SERIAL_HPP

// Boost:
#include <boost/serialization/nvp.hpp>

// This project:
#include <lib1/base.hpp>

namespace lib1 {

  template<class Archive>                                       
  void base::serialize(Archive & ar_, const unsigned int version_)
  {
  }

} // namespace lib1

#endif // LIB1_BASE_SERIAL_HPP
