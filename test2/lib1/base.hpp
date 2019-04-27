#ifndef LIB1_BASE_HPP
#define LIB1_BASE_HPP

// Standard library:
#include <iostream>

// - Boost:
#include <boost/serialization/access.hpp>

namespace lib1 {

  class base
  {
  public:
    
    base();
    
    virtual ~base();

    virtual void print(std::ostream & out_, const bool with_title_ = false) const = 0;
    
  private:
    
    friend class boost::serialization::access;  

    template<class Archive>                                       
    void serialize(Archive & ar_, const unsigned int version_);
        
  };

} // namespace lib1

#endif // LIB1_BASE_HPP
