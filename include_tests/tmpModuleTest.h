#ifndef TMP_MODULE_TESTS
#define TMP_MODULE_TESTS

#include "doctest.h"
#include "tmpModule.h"


TEST_CASE("TMP Test")
{
	unsigned uBufferSize = 10;
    TMPModule TMPModule(uBufferSize);

	SUBCASE("TMP Dummy test") {
        	CHECK(1 == 1);
    	}
}

#endif
