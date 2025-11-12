#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10,M=1e4+10;
ll n,m,mm,k,f[N],ans,sum,c[15],h[15][M],len[1010][1010],le[1010][1010],cnt[15];
bool p=true;
struct dazhao{
	ll a,b,w;
}zhao[N],ed[N];
bool cmp(dazhao x,dazhao y){
	return x.w<y.w;
}
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return ;
}
void dfs(ll id,ll cost){
	if(cost>ans) return ;
	if(id==k+1){
		//cout<<cost<<endl;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				le[i][j]=len[i][j];
			}
		}
		for(ll i=1;i<=k;i++){
			if(cnt[i]==0) continue;
			for(ll j=1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					le[j][l]=min(le[j][l],h[i][j]+h[i][l]);
				}
			}
		}
		mm=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(le[i][j]>=9e18) continue;
				zhao[++mm].a=i;zhao[mm].b=j;zhao[mm].w=le[i][j];
			}
		}
		for(ll i=1;i<=n;i++) f[i]=i;
		sum=0;
		sort(zhao+1,zhao+mm+1,cmp);
		for(ll i=1;i<=mm;i++){
			ll a=zhao[i].a,b=zhao[i].b;
			//cout<<a<<" "<<b<<" "<<zhao[i].w<<endl;
			if(find(a)!=find(b)){
				sum++;
				cost+=zhao[i].w;
				//cout<<cost<<endl;
				f[find(a)]=find(b);
			}
			if(cost>ans) return ;
			if(sum==n-1) break;
		}
		if(sum!=n-1) return ;
		ans=min(ans,cost);
		//cout<<ans<<" "<<cost<<endl;
		return ;
	}
	cnt[id]=0;
	dfs(id+1,cost);
	cnt[id]=1;
	//cout<<c[id]<<endl;
	dfs(id+1,cost+c[id]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		zhao[i].a=read();
		zhao[i].b=read();
		zhao[i].w=read();
	}
	if(k==0){
		sort(zhao+1,zhao+m+1,cmp);
		for(ll i=1;i<=m;i++){
			ll a=zhao[i].a,b=zhao[i].b;
			if(find(a)!=find(b)){
				sum++;
				ans+=zhao[i].w;
				f[find(a)]=find(b);
			}
			if(sum==n-1) break;
		}
		write(ans);
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		//cout<<c[i]<<endl;
		for(ll j=1;j<=n;j++){
			h[i][j]=read();
		}
	}
	ans=9e18;
	//cout<<ans<<endl;
	memset(len,127,sizeof(len));
	for(ll i=1;i<=m;i++){
		ll a=zhao[i].a,b=zhao[i].b;
		if(a>b) swap(a,b);
		len[a][b]=min(len[a][b],zhao[i].w);
	}
//		for(ll i=1;i<=n;i++){
//			for(ll j=i+1;j<=n;j++){
//				if(len[i][j]==9e18) continue;
//				ed[++mm].a=i;ed[mm].b=j;
//				ed[mm].w=len[i][j];
//			}
//		}
	dfs(1,0);
	//cout<<ans<<endl;
	write(ans);
	return 0;
}
