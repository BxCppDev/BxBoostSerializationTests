// From: https://github.com/boostorg/serialization/issues/109

#include <iostream>
#include <sstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

int main()
{
  std::ostringstream os;
  {
    boost::archive::xml_oarchive archive(os);
    int a = 42;
    archive & boost::serialization::make_nvp("foo", a);
    std::cout << " Wrote a=" << a << " to archive\n";
  }

  std::cout << "archive xml: " << os.str() << "\n";
  
  try {
    std::istringstream is(os.str());
    boost::archive::xml_iarchive archive(is);
    int a = 0;
    archive & boost::serialization::make_nvp("foo", a);
    try {
      archive & boost::serialization::make_nvp("not_there", a);
    } catch (const boost::archive::archive_exception &) {
      std::cout << "exception 1\n";
    }
    std::cout << " Read a=" << a << " from archive\n" << std::endl;
  } catch (...) {
    std::cout << "exception 2\n";
  }

  return 0;
}
