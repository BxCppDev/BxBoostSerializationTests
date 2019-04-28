// From https://github.com/boostorg/serialization/issues/82 by steronydh

#include <iostream>
#include <boost/archive/archive_exception.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/split_member.hpp>

namespace UtilityLibTest
{
  class XmlArchiveTest
  {
  public:
    XmlArchiveTest() { m_value = 4; }

    int Value() const { return m_value; }
    void Value(const int v) { m_value = v; }
  private:
    friend class boost::serialization::access;

    void load(boost::archive::xml_iarchive & ar, unsigned int version)
    {
      ar & BOOST_SERIALIZATION_NVP(m_value);
    }
    void save(boost::archive::xml_oarchive & ar, unsigned int version) const
    {
      ar & BOOST_SERIALIZATION_NVP(m_value);
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER();
    
  protected:
    int m_value;
  };

  class UnitTest1
  {
  public:

    static void XmlArchive_SaveLoad()
    {
      XmlArchiveTest store;

      // save block:
      std::stringstream xml(std::stringstream::out);
      {
        // archive scope:
        boost::archive::xml_oarchive archive(xml);
        archive & BOOST_SERIALIZATION_NVP(store);
      } // archive's destructor invocation implies the </boost_serialization> final XML tag.
      // xml.flush(); // probably not useful
      auto xml1 = xml.str();
      std::clog << "archive: " << xml1 << std::endl;
      
      store.Value(234);
      
      // load block:
      std::stringstream xml2;
      xml2 << xml1;
      {
        // archive scope:
        boost::archive::xml_iarchive archive2(xml2);
        archive2 & BOOST_SERIALIZATION_NVP(store);
      }
      std::clog << "store.Value=" << store.Value() << std::endl;
      if (4 != store.Value()) {
        std::clog << "4 != store.Value" << std::endl;
      }
    }

  };
}

int main()
{
  UtilityLibTest::UnitTest1::XmlArchive_SaveLoad();
  return 0;
}
