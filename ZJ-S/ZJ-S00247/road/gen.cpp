#include<bits/stdc++.h>
using namespace std;
mt19937 rd(random_device{}());
int main(){
    int N=10000,M=1000000,K=10;
    // N=rd()%50+1,M=N-1+rd()%500+1,K=rd()%11;
    printf("%d %d %d\n",N,M,K);
    for(int i=2;i<=N;i++) printf("%d %d %d\n",rd()%(i-1)+1,i,rd()%1000000001);
    for(int i=N;i<=M;i++) printf("%d %d %d\n",rd()%N+1,rd()%N+1,rd()%1000000001);
    for(int i=1;i<=K;i++) for(int j=0;j<=N;j++) printf("%d%c",rd()%1000000001,j==N?'\n':' ');
    return 0;
}