#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, y;
    cin >> p >> y;
    int ans = y;
    while(1){
        bool flg = true;
        for(int i = 2 ; i * i <= ans; i++){
            if(ans % i == 0){
                if(i <= p){
                    flg = false;
                    break;
                }
            }
        }
        if(!flg){
            ans--;
            continue;
        }
        else{
            break;
        }
    }
    if(ans <= p){
        cout << "-1\n";
        return 0;
    }
    cout << ans << endl;
    return 0;
}