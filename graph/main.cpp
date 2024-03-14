#include <iostream>

#include "graph_node.hpp"
#include "edge.hpp"

using std::cout;
using std::endl;

int main() {
    
    // create nodes
    // Inspired by the graph used for https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
    GraphNode A{'A'};
    GraphNode B{'B'};
    GraphNode C{'C'};
    GraphNode D{'D'};
    GraphNode E{'E'};
    GraphNode F{'F'};

    cout << "A.name: " << A.name << endl;

    // create edges
    /* Be aware that an edge names its nodes source and destination,
        but that there is no explicit directionality */
    Edge AB{&A, &B, 7};
    Edge AC{&A, &C, 9};
    Edge AF{&A, &F, 1};
    
    Edge BC{&B, &C, 10};
    Edge BD{&B, &D, 15};
    
    Edge CD{&C, &D, 11};
    Edge CF{&C, &F, 2};
    
    Edge DE{&D, &E, 6};

    Edge EF{&E, &F, 9};
  
    cout << "AB(src->name, dst->name, weight): (" << AB.source->name << ", " << AB.destination->name << ", "<< AB.weight << ")" << endl;

    // hook up the edges into the nodes
    
    // A <--------------------> B
    A.connected_to.push_back(&AB);
    B.connected_to.push_back(&AB);


    A.connected_to.push_back(&AC);
    C.connected_to.push_back(&AC);

    A.connected_to.push_back(&AF);
    F.connected_to.push_back(&AF);

    B.connected_to.push_back(&BC);
    C.connected_to.push_back(&BC);

    B.connected_to.push_back(&BD);
    D.connected_to.push_back(&BD);

    C.connected_to.push_back(&CD);
    D.connected_to.push_back(&CD);

    C.connected_to.push_back(&CF);
    F.connected_to.push_back(&CF);

    D.connected_to.push_back(&DE);
    E.connected_to.push_back(&DE);

    E.connected_to.push_back(&EF);
    F.connected_to.push_back(&EF);

    // source, destination complication might come up here!
    cout << "A.connected_to[0]->destination->name: " << A.connected_to[0]->destination->name << endl;

    return 0;
}