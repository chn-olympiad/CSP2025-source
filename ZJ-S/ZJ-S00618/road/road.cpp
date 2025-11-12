#include<bits/stdc++.h>
#define pi pair<int,int>
#define ay array<int,3>
#define int long long
#define fi first
#define se second
const int N=1e5+7;
const int M=2e6+7;
const int inf=9e18;
using namespace std;
int n,m,k;
int c[15],d[15][N],f[N];
ay a[M],b[M];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int read(){
	int x=0,f=1;char c;
	do{
		c=getchar();
		if(c=='-')f=-f;
	}
	while(c<'0'||c>'9');
	do{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
void solve(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		b[i][1]=read();b[i][2]=read();b[i][0]=read();
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0;
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		if(get(b[i][1])==get(b[i][2]))continue;
		f[get(b[i][1])]=get(b[i][2]);
		++cnt;
		a[cnt]=b[i];
	}
	int fl=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])fl=0;
		for(int j=1;j<=n;j++)d[i][j]=read();
	}
	int ans=inf;
	if(fl&&n>=1e3&&k>=10){
		int cnt=n-1;
		for(int j=1;j<=cnt;j++)b[j]=a[j];
		for(int j=1;j<=k;j++){
			int id=j+n;
			for(int t=1;t<=n;t++){
				cnt++;
				b[cnt]={d[j][t],id,t};
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		sort(b+1,b+cnt+1);
		int res=0;
		for(int i=1;i<=cnt;i++){
			if(get(b[i][1])==get(b[i][2]))continue;
			f[get(b[i][1])]=get(b[i][2]);
			res+=b[i][0];
		}
		cout<<res;
		return;
	}
	for(int i=0;i<(1<<k);i++){
		if(k>=10&&(double)clock()/CLOCKS_PER_SEC>0.95)break;
		int cnt=n-1,res=0;
		for(int j=1;j<=cnt;j++)b[j]=a[j];
		for(int j=1;j<=k;j++){
			int id=j+n;
			if((i>>j-1)&1){
				res+=c[j];
				for(int t=1;t<=n;t++){
					cnt++;
					b[cnt]={d[j][t],id,t};
				}
			}
		}
		sort(b+1,b+cnt+1);
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=cnt;i++){
			if(get(b[i][1])==get(b[i][2]))continue;
			f[get(b[i][1])]=get(b[i][2]);
			res+=b[i][0];
		}
		ans=min(ans,res);
	}     
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--)solve();
}