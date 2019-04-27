
#include <lib1/class1.hpp>

namespace lib1 {

  class1::class1()
  {
  }
        
  class1::class1(const bool flag_, const int32_t value_)
    : flag(flag_)
    , value(value_)
  {
  }
  
  class1::~class1()
  {
  }

  void class1::print(std::ostream & out_, const bool with_title_) const
  {
    if (with_title_) out_ << "class 1:" << std::endl;
    out_ << "+-- flag: " << std::boolalpha << flag << std::endl;
    out_ << "+-- value: " << value << std::endl;
  }

} // namespace lib1
