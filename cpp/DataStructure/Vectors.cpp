#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*
    vector<int> grades = {90, 85, 92}; 

    vector<int> v;        // empty vector
    vector<int> v2(5);    // size 5, all values = 0
    vector<int> v3(5,10); // size 5, all values = 10
    */
    vector<int> v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    for(int x : v){
        cout << x << " ";
    }

    return 0;
}