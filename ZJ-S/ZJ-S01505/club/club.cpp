#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0,sgn=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
    return x*sgn;
}
void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
long long t,n,a[100010][10];
long long Cnt[10],Ans,Tag[100010];
void Dfs(long long x){
    if(x>n){
        long long sum=0;
        for(int i=1;i<=n;i++)
            sum+=a[i][Tag[i]];
        Ans=max(Ans,sum);
        return;
    }
    for(int i=1;i<=3;i++)
        if(Cnt[i]<n/2){
            Cnt[i]++;
            Tag[x]=i;
            Dfs(x+1);
            Cnt[i]--;
        }
}
bool CHeck(){
    bool p=true;
    for(int i=1;i<=n;i++)
        for(int j=2;j<=3;j++)
            if(a[i][j]!=0){
                p=false;
                break;
            }
    return p;
}
long long SOlve(){
    long long b[100010];
    for(int i=1;i<=n;i++)
        b[i]=a[i][1];
    sort(b+1,b+n+1);
    long long sum=0;
    for(int i=n/2+1;i<=n;i++)
        sum+=b[i];
    return sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                a[i][j]=read();
        if(n<=10){
            Ans=0;
            Dfs(1);
            write(Ans);putchar('\n');
            continue;
        }
        if(CHeck()==true){
            write(SOlve());putchar('\n');
            continue;
        }

    }
    return 0;
}
