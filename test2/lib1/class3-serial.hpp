#ifndef LIB1_CLASS3_SERIAL_HPP
#define LIB1_CLASS3_SERIAL_HPP

// Boost:
#include <boost/serialization/nvp.hpp>

// This project:
#include <lib1/class3.hpp>
#include <lib1/class1-serial.hpp>

namespace lib1 {

  template<class Archive>                                       
  void class3::serialize(Archive & archive_, const unsigned int version_)
  {
    archive_ & boost::serialization::make_nvp("lib1__class1", 
                                              boost::serialization::base_object<lib1::class1>(*this));
    archive_ & boost::serialization::make_nvp("more", more);
  }

} // namespace lib1

#endif // LIB1_CLASS3_SERIAL_HPP
