#ifndef LIB1_ARCHIVES_INSTANTIATION_HPP
#define LIB1_ARCHIVES_INSTANTIATION_HPP

#include <lib1/archives_list.hpp>

#define LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,A)     \
  template void T::serialize(A & archive_,                      \
                             const unsigned int version_);      \
  /**/

#define LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL_IN(T)        \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::polymorphic_iarchive) \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::text_iarchive) \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::xml_iarchive) \
  /**/

#define LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL_OUT(T)       \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::polymorphic_oarchive) \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::text_oarchive) \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE(T,boost::archive::xml_oarchive) \
  /**/

#define LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL(T)   \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL_IN(T)      \
  LIB1_SERIALIZATION_CLASS_SERIALIZE_INSTANTIATE_ALL_OUT(T)     \
  /**/

#endif // LIB1_ARCHIVES_INSTANTIATION_HPP
