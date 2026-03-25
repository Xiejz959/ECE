#include "GamerMap.h"
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
    GamerMap g;

    // 测试 addGamer
    assert(g.addGamer("Alice"));
    assert(g.addGamer("Bob"));
    assert(!g.addGamer("Alice")); // duplicate

    // 测试 numGamers
    assert(g.numGamers() == 2);

    // 测试 hoursSpent
    assert(g.hoursSpent("Alice") == 0);
    assert(g.hoursSpent("Unknown") == -1);

    // 测试 play
    assert(g.play("Alice", 2.5));
    assert(g.hoursSpent("Alice") == 2.5);

    assert(!g.play("Unknown", 1.0)); // 不存在
    assert(!g.play("Alice", -1));    // 负数

    // 多次 play
    assert(g.play("Alice", 1.5));
    assert(g.hoursSpent("Alice") == 4.0);

    // print（人工看）
    cout << "=== Gamer List ===" << endl;
    g.print();

    cout << "Passed all tests" << endl;

    return 0;
}