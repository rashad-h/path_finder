#include "unity.h"
#include "input.h"


void test_read_map()
{
    FILE* map;
    int ans = read_map(map);

    TEST_ASSERT_EQUAL_INT (0, ans);
    
}


void setUp()
{

}
void tearDown()
{

}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_read_map);

    return UNITY_END();
}