#include "unity.h"
#include "logic.h"


void test_find_closest_point()
{
    //test case 1
    int ans = find_closest_point(53.805337, -1.551925);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, ans, "The find_closest_point failed!");
    TEST_ASSERT_EQUAL_INT (-2414, all_nodes[ans].id);
    // test case 2
    ans = find_closest_point(53.803600, -1.556471);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, ans, "The find_closest_point failed!");
    TEST_ASSERT_EQUAL_INT (1152071943, all_nodes[ans].id);
}

void test_find_shortest_path_Djikstra()
{
    struct NodeArray test_array;
    test_array = find_shortest_path_Djikstra (10, 200);
    TEST_ASSERT_NOT_NULL (test_array.array);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (0, test_array.length, "The length of the answer is zero");
    TEST_ASSERT_EQUAL_INT (22, test_array.length);
    
}

void test_find_shortest_path_Floyd()
{
    struct NodeArray test_array;
    test_array = find_shortest_path_Floyd (10, 200);
    TEST_ASSERT_NOT_NULL (test_array.array);
    TEST_ASSERT_NOT_EQUAL_MESSAGE (0, test_array.length, "The length of the answer is zero");
    TEST_ASSERT_EQUAL_INT (22, test_array.length);
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