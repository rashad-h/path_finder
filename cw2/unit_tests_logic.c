#include "unity.h"
#include "logic.h"


void test_find_closest_point()
{
    int ans = find_closest_point(53.804381, 1.552673);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, ans, "The find_closest_point failed!");
    TEST_ASSERT_EQUAL_INT (2458, ans);
}

void test_find_shortest_path_Djikstra()
{
    struct NodeArray test_array;
    test_array = find_shortest_path_Djikstra (3, 10);
    TEST_ASSERT_NOT_NULL (test_array.array);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (0, test_array.length, "The length of the answer is zero");

}

void test_find_shortest_path_Floyd()
{
    struct NodeArray test_array;
    test_array = find_shortest_path_Floyd (3, 10);
    TEST_ASSERT_NOT_NULL (test_array.array);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (0, test_array.length, "The length of the answer is zero");

}

void setUp()
{
    FILE* map_test;
    read_map(map_test);
}
void tearDown()
{

}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_find_closest_point);
    RUN_TEST(test_find_shortest_path_Djikstra);
    RUN_TEST(test_find_shortest_path_Floyd);

    return UNITY_END();
}