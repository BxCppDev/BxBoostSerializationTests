// Standard library:
#include <cstdlib>
#include <iostream>
#include <exception>
#include <memory>

// Boost library:
#include <boost/version.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>

// This project:
#include <lib1/class1.hpp>
#include <lib1/class2.hpp>
#include <lib1/class3.hpp>
#include <class4.hpp>

void save(std::string & sink_);
void load(const std::string & source_);

int main(int argc, char* argv[])
{
  int error_code = EXIT_SUCCESS;
  try {

    std::string buffer;
    save(buffer);
    std::clog << "buffer = '" << buffer << "'" << std::endl;
    load(buffer);

    std::clog << std::endl;
   } catch (std::exception & x) {
    std::cerr << "test2: error: " << x.what() << std::endl;
    error_code = EXIT_FAILURE;
  } catch (...) {
    std::cerr << "test2: error: " << "unexpected error!" << std::endl;
    error_code = EXIT_FAILURE;
  }
  return error_code;
}

void save(std::string & sink_)
{
  std::clog << "************ Entering save..." << std::endl;
  std::shared_ptr<lib1::base> s1(new lib1::class1(true, 12));
  std::shared_ptr<lib1::base> s2(new lib1::class2(42, "blah"));
  std::shared_ptr<lib1::base> s3(new lib1::class3(false, 666, "foo"));
  std::shared_ptr<lib1::base> s4(new class4(true, 333, "bar"));
  
  std::clog << "Objects to be saved : " << std::endl;
  s1->print(std::clog, true);
  std::clog << std::endl;
  s2->print(std::clog, true);
  std::clog << std::endl;
  s3->print(std::clog, true);
  std::clog << std::endl;
  s4->print(std::clog, true);
  std::clog << std::endl;
 
  std::ostringstream oss;
  {
    boost::archive::xml_oarchive ar(oss);
    ar & boost::serialization::make_nvp("s1", s1);
    ar & boost::serialization::make_nvp("s2", s2);
    ar & boost::serialization::make_nvp("s3", s3);
    ar & boost::serialization::make_nvp("s4", s4);
  }
  std::clog << "oss = '" << oss.str() << "'" << std::endl;
  sink_ = oss.str();
  std::clog << std::endl;
}

void load(const std::string & source_)
{
  std::clog << "************ Entering load..." << std::endl;
  std::shared_ptr<lib1::base> s1;
  std::shared_ptr<lib1::base> s2;
  std::shared_ptr<lib1::base> s3;
  std::shared_ptr<lib1::base> s4;
  
  std::istringstream iss(source_);
  {
    boost::archive::xml_iarchive ar(iss);
    ar & boost::serialization::make_nvp("s1", s1);
    ar & boost::serialization::make_nvp("s2", s2);
    ar & boost::serialization::make_nvp("s3", s3);
    ar & boost::serialization::make_nvp("s4", s4);
  }
  
  std::clog << "Loaded objects : " << std::endl;
  s1->print(std::clog, true);
  std::clog << std::endl;
  s2->print(std::clog, true);
  std::clog << std::endl;
  s3->print(std::clog, true);
  std::clog << std::endl;
  s4->print(std::clog, true);
  std::clog << std::endl;

  std::clog << std::endl;
}
