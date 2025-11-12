#include<bits/stdc++.h>
using namespace std;
int main(){
    system("g++ gen.cpp -o gen -O2&&g++ bf.cpp -o bf -O2 && g++ road.cpp -O2");
    int t=0;
    while(1){
        printf("%d\n",++t);
        system("./gen > road.in && ./bf&&./a.out");
        if(system("diff -Zq road.out road.ans")) return puts("WA"),0;
        puts("AC");
    }
}