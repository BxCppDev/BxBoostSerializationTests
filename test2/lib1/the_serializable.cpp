
// Boost:
#include <boost/serialization/export.hpp>

// This project:
#include <lib1/base-serial.hpp>
#include <lib1/class1-serial.hpp>
#include <lib1/class2-serial.hpp>
#include <lib1/class3-serial.hpp>
#include <lib1/archives_instantiation.hpp>

LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL(lib1::class1)
LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL(lib1::class2)
LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL(lib1::class3)
BOOST_CLASS_EXPORT_IMPLEMENT(lib1::class1)
BOOST_CLASS_EXPORT_IMPLEMENT(lib1::class2)
BOOST_CLASS_EXPORT_IMPLEMENT(lib1::class3)

// end
