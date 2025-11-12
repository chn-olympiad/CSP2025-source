#include<bits/stdc++.h>
using namespace std;
int n,m;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct Node{
    int val;
    bool flg;
    bool operator<(const Node b)const{return val<b.val;}
}lst[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n*m;i++) lst[i]={read(),i==1};
    sort(lst+1,lst+1+n*m);
    reverse(lst+1,lst+1+n*m);
    int id;
    for(int i=1;i<=n*m;i++) if(lst[i].flg){id=i;break;}
    int bel=id/(2*n),dpf=id%(2*n);
    if(dpf==0||dpf>n){
        cout<<(bel*2+2)<<" "<<((dpf==0)?1:((n+1)-(dpf-n)))<<endl;
    }else cout<<(bel*2+1)<<" "<<dpf<<endl;
    return 0;
}