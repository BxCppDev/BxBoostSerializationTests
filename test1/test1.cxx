// Standard library:
#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <vector>

// Boost library:
#include <boost/version.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/nvp.hpp>

void f_broken(std::string & sink_)
{
  sink_.clear(); // Start with an empty string
  std::clog << "************ Entering f_broken..." << std::endl;
  std::vector<int> outvec({4,3,2,1,0});
  for (const auto & value : outvec) {
    std::clog << "value to be saved = " << value << std::endl;
  }
  {
    // Hmm, here we put the buffer string stream AND the archive in the same scope:
    std::ostringstream oss;
    boost::archive::xml_oarchive ar(oss);
    ar & boost::serialization::make_nvp("vec", outvec);
    std::clog << "oss = '" << oss.str() << "'" << std::endl;
    sink_ = oss.str(); // Fill the string before the buffer string stream is destroyed
                       // but the archive destructor has not been invoked yet!
  } // Archive destructor is invoked here so the "</boost_serialization>" final XML tag
  // is written too late with respect to the 'sink_' buffer string above which is
  // thus malformed! See f below for the fix.
  // For 1.65, this issue is not detected while deserializing the archive
  // but 1.68 fails and throws an exception.
  std::clog << std::endl;
}

void f(std::string & sink_)
{
  std::clog << "************ Entering f..." << std::endl;
  std::vector<int> outvec({4,3,2,1,0});
  for (const auto & value : outvec) {
    std::clog << "value to be saved = " << value << std::endl;
  }
  std::ostringstream oss;
  {
    // Start the archive scope block:
    boost::archive::xml_oarchive ar(oss);
    ar & boost::serialization::make_nvp("vec", outvec);
    // Stop the archive scope block.
  } // Archive destructor is invoked here and the final XML tag is written in the string buffer.
  std::clog << "oss = '" << oss.str() << "'" << std::endl;
  sink_ = oss.str(); // Fill the buffer string with the proper XMl content
  std::clog << std::endl;
}

void g(const std::string & source_)
{
  std::clog << "************ Entering g..." << std::endl;
  std::vector<int> invec;
  {
    std::istringstream iss(source_);
    {
      boost::archive::xml_iarchive ar(iss);
      ar & boost::serialization::make_nvp("vec", invec);
    } // Archive destructor is invoked here and required the final XML tag (at least for Boost 1.68)
    for (const auto & value : invec) {
      std::clog << "loaded value = " << value << std::endl;
    }
  }
  std::clog << std::endl;
}

int main(int argc, char* argv[])
{
  int error_code = EXIT_SUCCESS;
  try {

    // The part shows the issue:
    std::string broken_buffer;
    f_broken(broken_buffer);
    std::clog << "broken_buffer = '" << broken_buffer << "'" << std::endl;
    std::clog << std::endl;
#if BOOST_VERSION <= 106501
    // For now this code works up to 106501 but breaks with 106800 (106600, 106700, 106900 were not tested).
    // Deserialization of the broken_buffer does not claim even if
    // the final "</boost_serialization>" XML tag is missing!
    std::clog << "<=106501 PATH" << std::endl;
    g(broken_buffer);
    std::clog << "<=106501 PATH" << std::endl;
#endif

    // This part works correctly for both tested versions of Boost: 106501 and 106800
    std::string buffer;
    f(buffer);    
    std::clog << "buffer = '" << buffer << "'" << std::endl;
    std::clog << std::endl;
    g(buffer);
    
  } catch (std::exception & x) {
    std::cerr << "test1: error: " << x.what() << std::endl;
    error_code = EXIT_FAILURE;
  } catch (...) {
    std::cerr << "test1: error: " << "unexpected error!" << std::endl;
    error_code = EXIT_FAILURE;
  }
  return error_code;
}
