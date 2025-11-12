#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int a,b;
    int ida,idb;
}t[100005];

int ta[100005],tb[100005],tc[100005];

bool cmp(Node t1,Node t2){
    return (t1.a-t1.b)>(t2.a-t2.b);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int temp;
    scanf("%d",&temp);
    while(temp--){
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&ta[i],&tb[i],&tc[i]);
            if(ta[i]>=tb[i]&&tb[i]>=tc[i]){
                t[i].a=ta[i];
                t[i].ida=1;
                t[i].b=tb[i];
                t[i].idb=2;
            }else if(tb[i]>=ta[i]&&ta[i]>=tc[i]){
                t[i].a=tb[i];
                t[i].ida=2;
                t[i].b=ta[i];
                t[i].idb=1;
            }else if(tc[i]>=tb[i]&&tb[i]>=ta[i]){
                t[i].a=tc[i];
                t[i].ida=3;
                t[i].b=tb[i];
                t[i].idb=2;
            }else if(tb[i]>=tc[i]&&tc[i]>=ta[i]){
                t[i].a=tb[i];
                t[i].ida=2;
                t[i].b=tc[i];
                t[i].idb=3;
            }else if(ta[i]>=tc[i]&&tc[i]>=tb[i]){
                t[i].a=ta[i];
                t[i].ida=1;
                t[i].b=tc[i];
                t[i].idb=3;
            }else if(tc[i]>=ta[i]&&ta[i]>=tb[i]){
                t[i].a=tc[i];
                t[i].ida=3;
                t[i].b=ta[i];
                t[i].idb=1;
            }
        }
        sort(t+1,t+1+n,cmp);
        int cnt[4]={0};
        for(int i=1;i<=n;i++){
            if(cnt[t[i].ida]>=n/2){
                ans+=t[i].b;
                cnt[t[i].idb]++;
            }else{
                ans+=t[i].a;
                cnt[t[i].ida]++;
            }
        }
        cout <<ans<< endl;
    }
    return 0;
}
