#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
#define rf(i,j,k) for(int i=j;i>=k;i--)
#define mm(i) memset(i,0,sizeof i)
#define rm(i) memset(i,0x3f,sizeof i)
const int N=2e6+10;
const int mo=998244353;
const double pi=acos(-1.0);
using namespace std;
int n,m,k,ans;
int f[N],a[N];
struct road{
	int u,v,w;
}b[N];
int u,v,w,x;
bool cmp(road x,road y){
	return x.w<y.w;
}
int findf(int k){
	return f[k]==k?k:f[k]=findf(f[k]);
}
void bing(int x,int y){
	int fx=findf(x),fy=findf(y);
	if(fx!=fy) f[fx]=fy;
}
void kru(){
	f(i,1,m){
		int u=b[i].u,v=b[i].v,w=b[i].w;
		if(findf(u)!=findf(v)){
			bing(u,v);
			ans+=w;	
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	f(i,1,m){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	f(i,1,n) f[i]=i;
	f(i,1,k){
		cin>>x;
		int cnt=0;
		f(j,1,n){
			cin>>a[j];
			if(!a[j]) cnt=j;
		}
		f(j,1,n){
			if(j!=cnt){
				b[++m].u=cnt;
				b[m].v=j;
				b[m].w=a[j];
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	kru();
	cout<<ans;
	return 0;
}
