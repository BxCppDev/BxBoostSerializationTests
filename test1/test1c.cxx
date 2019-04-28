
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
    int pos = is.tellg(); // we save the position of the input stream after last success
    std::cout << "pos after last successfull read op: " << pos << "\n";
    try {
      archive & boost::serialization::make_nvp("not_there", a);
    } catch (const boost::archive::archive_exception &) {
      std::cout << "exception 1\n";
      int fail_pos = is.tellg(); // we save the position of the input stream after the failure
      std::cout << "pos after failed read op: " << fail_pos << "\n";
      // we restore the position of the stream after the last success
      // in order to let the destructor of the XML archive to read the
      // final </boost_serialization> tag:
      is.seekg(pos, std::ios_base::beg);
    }
    std::cout << " Read a=" << a << " from archive\n" << std::endl;
    pos = is.tellg(); // we save the current position of the input stream 
    std::cout << "pos before archive destruction: " << pos << "\n";
  } catch (...) {
    std::cout << "exception 2\n";
  }

  return 0;
}
