#include<bits/stdc++.h>
using namespace std;

mt19937 mt_rand(random_device{}());
inline int rand(int l,int r){
    return uniform_int_distribution<int>(l,r)(mt_rand);
}

int main(){
    int n=rand(1,3);
    printf("%d %d\n",n,rand(1,n));
    for(int i=1;i<=n;i++)printf("%d",rand(0,1));
    printf("\n");
    for(int i=1;i<=n;i++)printf("%d%c",rand(0,n)," \n"[i==n]);
    return 0;
}