#include<bits/stdc++.h>
using namespace std;
mt19937 rd(random_device{}());
int main(){
    int N=5000000/26,Q=5000000/26;
     N=rd()%100+1,Q=rd()%100+1;
    printf("%d %d\n",N,Q);
    for(int i=1;i<=N;i++){
        // puts("aaaaaaaaaaaaa bbbbbbbbbbbbb");
        int len=rd()%10+1;
        string aa="",bb="";
        while(aa==bb){
            aa="",bb="";
            for(int j=1;j<=len;j++) aa+=(rd()%2+'a');
            for(int j=1;j<=len;j++) bb+=(rd()%2+'a');
        }
        cout<<aa<<' '<<bb<<'\n';
    }
    while(Q--){
        // puts("aaaaaaaaaaaaa bbbbbbbbbbbbb");
        int len=rd()%10+1;
        string aa="",bb="";
        while(aa==bb){
            aa="",bb="";
            for(int j=1;j<=len;j++) aa+=(rd()%2+'a');
            for(int j=1;j<=len;j++) bb+=(rd()%2+'a');
        }
        cout<<aa<<' '<<bb<<'\n';
    }
    return 0;
}