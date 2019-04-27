#ifndef LIB1_CLASS1_HPP
#define LIB1_CLASS1_HPP

// Standard library:
#include <cstdint>

// - Boost:
#include <boost/serialization/access.hpp>

// This project:
#include <lib1/base.hpp>

namespace lib1 {

  class class1
    : public base
  {
  public:
    
    class1();
   
    class1(const bool, const int32_t);
     
    virtual ~class1();

    void print(std::ostream & out_, const bool with_title_ = false) const override;
 
    bool    flag  = false;
    int32_t value = 0;
    
  private:
    
    friend class boost::serialization::access;  

    template<class Archive>                                       
    void serialize(Archive & ar_, const unsigned int version_);
        
  };

} // namespace lib1

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(lib1::class1, "lib1::class1")


#endif // LIB1_CLASS1_HPP
