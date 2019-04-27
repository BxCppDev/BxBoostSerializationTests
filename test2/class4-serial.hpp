#ifndef CLASS4_SERIAL_HPP
#define CLASS4_SERIAL_HPP

// Boost:
#include <boost/serialization/nvp.hpp>

// This project:
#include <class4.hpp>
#include <lib1/class1-serial.hpp>

template<class Archive>                                       
void class4::serialize(Archive & archive_, const unsigned int version_)
{
  archive_ & boost::serialization::make_nvp("lib1__class1", 
                                            boost::serialization::base_object<lib1::class1>(*this));
  archive_ & boost::serialization::make_nvp("more", more);
}

#endif // CLASS4_SERIAL_HPP
