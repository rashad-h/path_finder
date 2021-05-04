#include "unity.h"
#include "graphics.h"


void test_show_results()
{
    struct NodeArray test_nodes;
    test_nodes.array = (struct Node* ) malloc(3 * sizeof(struct Node));
    test_nodes.length = 3;
    test_nodes.array->id = 0;
    test_nodes.array->lat = 3.1;
    test_nodes.array->lon = 1.2;

    (test_nodes.array+2)->id = 1;
    (test_nodes.array+2)->lat = 1.5;
    (test_nodes.array+2)->lon = 1.9;

    (test_nodes.array+1)->id = 2;
    (test_nodes.array+1)->lat = 2.3;
    (test_nodes.array+1)->lon = 2.8;
    
    int ans = show_results(test_nodes);
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
    RUN_TEST(test_show_results);

    return UNITY_END();
}