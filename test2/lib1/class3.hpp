#ifndef LIB1_CLASS3_HPP
#define LIB1_CLASS3_HPP

// Standard library:
#include <cstdint>
#include <string>

// - Boost:
#include <boost/serialization/access.hpp>

// This project:
#include <lib1/class1.hpp>

namespace lib1 {

  class class3
    : public class1
  {
  public:
    
    class3();
    
    class3(const bool, const int32_t, const std::string &);
    
    virtual ~class3();

    void print(std::ostream & out_, const bool with_title_ = false) const override;
 
    std::string more;
    
  private:
    
    friend class boost::serialization::access;  

    template<class Archive>                                       
    void serialize(Archive & ar_, const unsigned int version_);
        
  };

} // namespace lib1

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(lib1::class3, "lib1::class3")

#endif // LIB1_CLASS3_HPP
