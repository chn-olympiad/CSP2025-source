#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t=0;
    while (1){
        ++t;
        system("./mkdata");
        system("./bf");
        system("./road");
        if (system("diff road.out road.ans")){
            cout<<"WA\n";
            break;
        }
        cout<<"Test Case "<<t<<" : Accepted\n";
    }
}