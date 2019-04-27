#include <lib1/class3.hpp>

namespace lib1 {

  class3::class3()
  {
  }
        
  class3::class3(const bool flag_, const int32_t value_, const std::string & more_)
    : class1(flag_, value_)
    , more(more_)
  {
  }
  
  class3::~class3()
  {
  }

  void class3::print(std::ostream & out_, const bool with_title_) const
  {
    if (with_title_) out_ << "class 3:" << std::endl;
    this->class1::print(out_);
    out_ << "+-- more: '" << more << "'" << std::endl;
  }

} // namespace lib1
