#ifndef CLASS4_HPP
#define CLASS4_HPP

// Standard library:
#include <cstdint>
#include <string>

// - Boost:
#include <boost/serialization/access.hpp>

// This project:
#include <lib1/class1.hpp>

class class4
  : public lib1::class1
{
public:
    
  class4();
    
  class4(const bool, const int32_t, const std::string &);
    
  virtual ~class4();

  void print(std::ostream & out_, const bool with_title_ = false) const override;
 
  std::string more;
    
private:
    
  friend class boost::serialization::access;  

  template<class Archive>                                       
  void serialize(Archive & ar_, const unsigned int version_);
        
};

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(class4, "class4")

#endif // LIB1_CLASS4_HPP
