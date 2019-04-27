#ifndef LIB1_CLASS1_SERIAL_HPP
#define LIB1_CLASS1_SERIAL_HPP

// Boost:
#include <boost/serialization/nvp.hpp>

// This project:
#include <lib1/class1.hpp>
#include <lib1/base-serial.hpp>

namespace lib1 {

  template<class Archive>                                       
  void class1::serialize(Archive & archive_, const unsigned int version_)
  {
    archive_ & boost::serialization::make_nvp("lib1__base", 
                                              boost::serialization::base_object<lib1::base>(*this));
    archive_ & boost::serialization::make_nvp("flag", flag);
    archive_ & boost::serialization::make_nvp("value", value);  
  }

} // namespace lib1

#endif // LIB1_CLASS1_SERIAL_HPP
