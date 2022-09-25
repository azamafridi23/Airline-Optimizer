// TO TEST  flight_optimizer7.h
// flight_optimizer6.h is OKAY

#include <iostream>
#include "flight_optimizer8.h"
using namespace std;

int main()
{

    // Test 3
    flight g1;
    g1.init();
    g1.add_edge3(0, 0, 1, 2,1.5);
    g1.add_edge3(0, 0, 3, 2,1);
    g1.add_edge3(0, 1, 3, 3,1.5);
    g1.add_edge3(0, 1, 4, 1,2);
    g1.add_edge3(0, 3, 4, 1,1);
    g1.add_edge3(0, 4, 2, 2,1.5);
    g1.add_edge3(0, 2, 0, 1,2.5);

    g1.add_edge3(1, 0, 4, 3,3);
    g1.add_edge3(1, 0, 2, 5,1.5);
    g1.add_edge3(1, 1, 2, 2,2);
    g1.add_edge3(1, 2, 3, 1,1);
    g1.add_edge3(1, 3, 4, 1,1);
    g1.add_edge3(1, 4, 1, 3,2);
    g1.add_edge3(1, 1, 3, 4,1.5);

    //No graph
    // flight g1;
    // g1.init();
    // g1.add_edge(0, 0, 1, 3);
    // g1.add_edge(0, 1, 4, 3);
    // g1.add_edge(0, 4, 2, 3);
    // g1.add_edge(0, 2, 3, 3);

    // g1.add_edge(1, 0, 2, 1);
    // g1.add_edge(1, 2, 1, 1);
    // g1.add_edge(1, 1, 4, 1);


    // TESTING DIFFICULT
    // Test 1
    // flight g1;
    // g1.init();
    // g1.add_edge3(0,0,1,4,1.5);
    // g1.add_edge3(0,1,4,1,1);
    // g1.add_edge3(0,4,2,2,1.5);
    // g1.add_edge3(0,2,3,3,2.5);

    // g1.add_edge3(1,0,2,1,1.5);
    // g1.add_edge3(1,2,1,1,1);
    // g1.add_edge3(1,1,4,3,1.5);

    //Test 2
    // flight g1;
    // g1.init();
    // g1.add_edge3(0,0,2,2,1.5);
    // g1.add_edge3(0,2,3,5,1);
    // g1.add_edge3(0,2,1,2,1.5);
    // g1.add_edge3(0,3,1,2,1);
    // g1.add_edge3(0,3,4,6,1);
    // g1.add_edge3(0,1,4,1,3);
    // g1.add_edge3(0,1,0,7,3);
    // g1.add_edge3(0,4,0,3,2);

    // g1.add_edge3(1,0,1,1,1);
    // g1.add_edge3(1,1,3,1,2);
    // g1.add_edge3(1,1,4,3,4);
    // g1.add_edge3(1,3,2,2,1);
    // g1.add_edge3(1,2,0,4,2);
    // g1.add_edge3(1,2,4,3,2);

    // g1.add_edge3(2,0,4,1,2.5);
    // g1.add_edge3(2,4,1,3,3);
    // g1.add_edge3(2,4,2,1,2);
    // g1.add_edge3(2,1,2,3,2);
    // g1.add_edge3(2,1,3,2,2);
    // g1.add_edge3(2,2,3,2,1);
    // g1.add_edge3(2,3,0,1,2);


    // Test 3 (No path exists)
    // flight g1;
    // g1.init();
    // g1.add_edge(0,0,1,1);
    // g1.add_edge(0,0,2,1);
    // g1.add_edge(1,1,3,1);
    // g1.add_edge(1,2,3,4);

    g1.new_matrix_former();
    g1.display_paths(0,4);
    g1.find_paths2(0,4);
    g1.comparator2();

    return 0;
}