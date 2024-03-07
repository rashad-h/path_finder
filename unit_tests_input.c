#include "unity.h"
#include "input.h"

// function used to read map and initilize the program
// return 0 if successful, 1 otherwise
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