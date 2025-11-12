#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ct;
int main(){
    while(1){
        printf("Running on test %lld\n",++ct);
        system("./data");
        system("./t");
        system("./t2");
        if(system("diff road.out baoli.out")){
            printf("WA");
            return 0;
        }
        printf("AC\n");
    }
    return 0;
}