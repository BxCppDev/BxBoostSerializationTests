
#include <lib1/class2.hpp>

namespace lib1 {

  class2::class2()
  {
  }
      
  class2::class2(const uint32_t number_, const std::string & word_)
    : number(number_)
    , word(word_)
  {
  }
  
  class2::~class2()
  {
  }

  void class2::print(std::ostream & out_, const bool with_title_) const
  {
    if (with_title_) out_ << "class 2:" << std::endl;
    out_ << "+-- number: " << number << std::endl;
    out_ << "+-- word: '" << word << "'" << std::endl;
  }

} // namespace lib1
