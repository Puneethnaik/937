#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> S;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        if(val){
            S.insert(val);
        }
    }
    cout << S.size() << endl;
    return 0;
}