#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double eps=1e-12;
const int N=1e6+10;
#define ul u<<1
#define ur u<<1|1
#define first fi
#define second se
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct ed{
    int u,v;ll w;
    bool operator < (const ed x)const{
        return w<x.w;
    }
}a[N],b[N*2];
int n,m,p[N*2],k;
ll con[16][10010];
ll ans=1e18,sum;
int find(int x){
    if(x!=p[x]){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        u=read();v=read();w=read();
        a[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            con[i][j]=read();
        }
    }
    int nm=0;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        int pa=find(a[i].u),pb=find(a[i].v);
        if(pa!=pb){
            p[pa]=pb;
            a[++nm]=a[i];
        }else if(nm<=20010){
            a[++nm]=a[i];
        }
    }
    for(int ma=0;ma<(1<<k);ma++){
        sum=0;
        for(int i=1;i<=nm;i++){
            b[i]=a[i];
        }
        int cnt=nm,node=n;
        for(int i=0;i<k;i++){
            if((ma>>i)&1){
                sum+=con[i+1][0];
                node++;
                for(int j=1;j<=n;j++){
                    b[++cnt]={node,j,con[i+1][j]};
                }
            }
        }
        for(int i=1;i<=node;i++){
            p[i]=i;
        }
        sort(b+1,b+1+cnt);
        for(int i=1;i<=cnt;i++){
            int pa=find(b[i].u),pb=find(b[i].v);
            if(pa!=pb){
                p[pa]=pb;
                sum+=b[i].w;
            }
        }
        //cout<<sum<<"\n";
        ans=min(ans,sum);
    }
    cout<<ans;
	return 0;
}