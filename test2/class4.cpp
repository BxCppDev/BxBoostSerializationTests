#include <class4.hpp>

class4::class4()
{
}
        
class4::class4(const bool flag_, const int32_t value_, const std::string & more_)
  : class1(flag_, value_)
  , more(more_)
{
}
  
class4::~class4()
{
}

void class4::print(std::ostream & out_, const bool with_title_) const
{
  if (with_title_) out_ << "class 4:" << std::endl;
  this->class1::print(out_);
  out_ << "+-- more: '" << more << "'" << std::endl;
}
