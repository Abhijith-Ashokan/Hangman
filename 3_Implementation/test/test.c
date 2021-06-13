 #include "unity.h"
#include "func.h"
void setUp(){}
void tearDown(){}
void test_wlen(void)
{TEST_ASSERT_EQUAL(6,wlen("yellow"));
TEST_ASSERT_EQUAL(6,wlen("banana"));}
int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_wlen);
    return UNITY_END();
}
