#include<bits/stdc++.h>
using namespace std;
int main(){
    system("g++ gen.cpp -o gen -O2&&g++ bf.cpp -o bf -O2 && g++ replace.cpp -O2");
    int t=0;
    while(1){
        printf("%d\n",++t);
        system("./gen > replace.in && ./bf < replace.in > replace.ans&&./a.out ");
        if(system("diff -Zq replace.out replace.ans")) return puts("WA"),0;
        puts("AC");
    }
}