#include<bits/stdc++.h>
using namespace std;

mt19937 mt_rand(random_device{}());
inline int rand(int l,int r){
    return uniform_int_distribution<int>(l,r)(mt_rand);
}

int main(){
    int n=rand(2,5),m=rand(n-1,10),k=rand(0,3);
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<n;i++){
        printf("%d %d %d\n",rand(1,i),i+1,rand(0,1e9));
    }
    for(int i=n;i<=m;i++){
        int u,v;
        u=rand(1,n),v=rand(1,n-1);
        v+=v>=u;
        printf("%d %d %d\n",u,v,rand(0,1e9));
    }
    for(int i=0;i<k;i++){
        printf("%d",rand(0,1e9));
        for(int i=1;i<=n;i++)printf(" %d",rand(0,1e9));
        printf("\n");
    }
    return 0;
}