#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t=0;
    while (1){
        ++t;
        system("./mkdata");
        system("./bf");
        system("./club");
        if (system("diff club.out club.ans")){
            cout<<"WA\n";
            break;
        }
        cout<<"Test Case "<<t<<" : Accepted\n";
    }
}