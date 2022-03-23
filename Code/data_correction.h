#include <map>
#include <iostream>
using namespace std;
struct Coordinate{
    int x;
    int y;
}
map<int, Coordinate> nodeData(string filename);
