#ifndef LIB1_CLASS2_HPP
#define LIB1_CLASS2_HPP

// Standard library:
#include <cstdint>
#include <string>

// - Boost:
#include <boost/serialization/access.hpp>

// This project:
#include <lib1/base.hpp>

namespace lib1 {

  class class2
    : public base
  {
  public:
    
    class2();
    
    class2(const uint32_t, const std::string &);
    
    virtual ~class2();

    void print(std::ostream & out_, const bool with_title_ = false) const override;
 
    uint32_t    number = 0;
    std::string word;
    
  private:
    
    friend class boost::serialization::access;  

    template<class Archive>                                       
    void serialize(Archive & ar_, const unsigned int version_);
        
  };

} // namespace lib1

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(lib1::class2, "lib1::class2")

#endif // LIB1_CLASS2_HPP
