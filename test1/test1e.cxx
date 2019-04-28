
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <sstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <boost/serialization/optional.hpp>

int main()
{
  srand(time(NULL));
  std::ostringstream os;
  {
    boost::archive::xml_oarchive archive(os);
    int a = 42;
    boost::optional<int> b;
    int c = 12;
    int p = rand() % 100;
    if (p < 50) {
      b = 666;
    }
    archive & boost::serialization::make_nvp("foo",   a);
    archive & boost::serialization::make_nvp("maybe", b);
    archive & boost::serialization::make_nvp("bar",   c);
    std::cout << " Wrote a=" << a << " to archive\n";
    if (b.is_initialized()) {
      std::cout << " Wrote b=" << b.value() << " to archive\n";
    } else {
      std::cout << " Optional b is marked uninitialized to archive\n";
    }
    std::cout << " Wrote c=" << c << " to archive\n";
  }

  std::cout << "archive xml: " << os.str() << "\n";
  
  try {
    std::istringstream is(os.str());
    int pos = is.tellg();
    boost::archive::xml_iarchive archive(is);
    int a = 0;
    boost::optional<int> b;
    int c = 0;
    archive & boost::serialization::make_nvp("first",  a);
    archive & boost::serialization::make_nvp("middle", b);
    archive & boost::serialization::make_nvp("last",   c);
    std::cout << " Read a=" << a << " from archive\n";
    if (b.is_initialized()) {
      std::cout << " Read b=" << b.value() << " from archive\n";
    } else {
      std::cout << " Uninitialized b from archive\n";
    }
    std::cout << " Read c=" << c << " from archive\n";     
  } catch (const std::exception & error2) {
    std::cerr << "exception 2 : " << error2.what() << "\n";
  } catch (...) {
    std::cout << "exception 2 : unexpected\n";
  }
  
  return 0;
}
