#ifndef LIB1_CLASS2_SERIAL_HPP
#define LIB1_CLASS2_SERIAL_HPP

// Boost:
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/string.hpp>

// This project:
#include <lib1/class2.hpp>
#include <lib1/base-serial.hpp>

namespace lib1 {

  template<class Archive>                                       
  void class2::serialize(Archive & archive_, const unsigned int version_)
  {
    archive_ & boost::serialization::make_nvp("lib1__base", 
                                              boost::serialization::base_object<lib1::base>(*this));
    archive_ & boost::serialization::make_nvp("number", number);
    archive_ & boost::serialization::make_nvp("word", word);  
  }

} // namespace lib1

#endif // LIB1_CLASS2_SERIAL_HPP
