
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <sstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

int main()
{
  srand(time(NULL));
  std::ostringstream os;
  {
    boost::archive::xml_oarchive archive(os);
    int a = 42;
    int b = 666;
    int c = 12;
    int p = rand() % 100;
    bool archive_has_b = false;
    if (p < 50) {
      archive_has_b = true;
    }
    archive & boost::serialization::make_nvp("foo", a);
    if (archive_has_b) {
      archive & boost::serialization::make_nvp("maybe", b);
    }
    archive & boost::serialization::make_nvp("bar", c);
    std::cout << " Wrote a=" << a << " to archive\n";
    if (archive_has_b) {
      std::cout << " Wrote b=" << b << " to archive\n";
    } else {
      std::cout << " b was not written to archive\n";
    }
    std::cout << " Wrote c=" << c << " to archive\n";
  }

  std::cout << "archive xml: " << os.str() << "\n";
  
  try {
    std::istringstream is(os.str());
    int pos = is.tellg();
    boost::archive::xml_iarchive archive(is);

    // Hmmm! What is the aim of the no_xml_tag_checking flag is not check is ever done ?
    // boost::archive::xml_iarchive archive(is, boost::archive::no_xml_tag_checking);
    // std::clog << "**** TAG = "
    //           << (archive.get_flags() & boost::archive::no_xml_tag_checking)
    //           << std::endl;
    
    pos = is.tellg(); // we save the position of the input stream before reading values
    std::cout << "pos after reading the XML archive header and before reading a: " << pos << "\n";
    int a = 0;
    int b = 0;
    int c = 0;
    bool archive_has_b = false;
    bool archive_has_c = false;
    archive & boost::serialization::make_nvp("first", a);
    pos = is.tellg(); // we save the position of the input stream after last success
    std::cout << "pos after reading a: " << pos << " with a=" << a << "\n";
    try {
      archive & boost::serialization::make_nvp("middle_perhaps", b);
      archive_has_b = true;
      pos = is.tellg();
      std::cout << "pos after reading b: " << pos << " with b=" << b << "\n";
    } catch (const std::exception & error1) {
      std::cerr << "exception 1 : " << error1.what() << "\n";
      int fail_pos = is.tellg(); // we save the position of the input stream after the failure
      std::cout << "pos after failed read op: " << fail_pos << "\n";
      // we restore the position of the stream after the last success
      // in order continue the deserialization:
      is.seekg(pos, std::ios_base::beg);
    } 

    try {
      archive & boost::serialization::make_nvp("last", c);
      archive_has_c = true;
      pos = is.tellg(); // we save the current position of the input stream 
      std::cout << "pos after reading c: " << pos << " with c=" << c << "\n";
    } catch (const std::exception & error1) {
      std::cerr << "exception 1 : " << error1.what() << "\n";
      int fail_pos = is.tellg(); // we save the position of the input stream after the failure
      std::cout << "pos after failed read op: " << fail_pos << "\n";
      // we restore the position of the stream after the last success
      // in order to let the destructor of the XML archive to read the
      // final </boost_serialization> tag:
      is.seekg(pos, std::ios_base::beg);
    }
    
    std::cout << " Read a=" << a << " from archive\n";
    if (archive_has_b) {
      std::cout << " Read b=" << b << " from archive\n";
    } else {
      std::cout << " b was not read from archive\n";
    }
    if (archive_has_c) {
      std::cout << " Read c=" << c << " from archive\n";
    } else {
      std::cout << " c was not read from archive\n";
    }

    // Ugly hack to restore the proper values:
    if (archive_has_b and not archive_has_c) {
      std::cout << " Applying the hacky fix...\n";
      c = b;
      b = 0;
      std::cout << " Fixed b=" << b << "\n";
      std::cout << " Fixed c=" << c << "\n";
    }
    
    std::cout << "pos before archive destruction: " << pos << "\n";
  } catch (const std::exception & error2) {
    std::cerr << "exception 2 : " << error2.what() << "\n";
  }
  
  return 0;
}
