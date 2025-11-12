#include<bits/stdc++.h>
using namespace std;
mt19937 rd(random_device{}());
int main(){
    int N=500,M=250;
    printf("%d %d\n",N,M);
    for(int i=1;i<=N;i++) putchar('0'+rd()%2);puts("");
    for(int i=1;i<=N;i++) printf("%d%c",rd()%N+1,i==N?'\n':' ');
}