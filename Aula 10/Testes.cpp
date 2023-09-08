#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int> vec = {0,1,1,2,3,5,8,13,21};



    for(auto x = vec.begin(); x != vec.end(); x++){
        cout << *x << endl;
    }

    vector<int>::iterator it;
    it = vec.begin();
    advance(it,5);
    vec.insert(it,-7);
    cout << "-----------------------" << endl;

    for(auto x = vec.begin(); x != vec.end(); x++){
        cout << *x << endl;
    }

    
    return 0;
}