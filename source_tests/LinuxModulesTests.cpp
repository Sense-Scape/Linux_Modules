#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"

TEST_CASE("Generic Test")
{
    SUBCASE("Checking default constructor") {
        CHECK(1==1);
    }

}
