#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll x,y,z;
};int n,m,k;
int f[10005];
void init(int x){
	for(int i=1;i<=x;i++)f[i]=i;
}
int fa(int x){
	if(f[x]==x)return x;
	return f[x]=fa(f[x]);
}
void unq(int x,int y){
	if(x>y)swap(x,y);
	f[fa(y)]=fa(x);
}
node v[1200005];
ll a[13][10005];
bool cmp(node x,node y){
	//if(x.x==0)return 0;
	return x.z<y.z;
}
ll sl(int o){
	ll res=0;map<int,int>s;
	for(int i=1;i<=k;i++){
		if(o&1){
			s[n+i]=1;
			res+=a[i][0];
		}
		o>>=1;
	}
	init(n+k);
	for(int i=1;i<=m;i++){
		if(v[i].y>n and !s[v[i].y])continue;
		//cout<<v[i].x<<' '<<v[i].y<<" "<<v[i].z<<endl;
		if(fa(v[i].x)==fa(v[i].y))continue;
		res+=v[i].z;
		unq(v[i].x,v[i].y);
	}
	
	return res;
}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//memset(v,0x3f,sizeof v);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>v[i].x>>v[i].y>>v[i].z;
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++)cin>>a[i][j],v[++m]={j,n+i,a[i][j]};
	}//cout<<"!";
	ll ans=1e12;
	sort(v+1,v+1+m,cmp);
	//for(int i=1;i<=m;i++)cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
	//cout<<(1<<k)<<endl;
	for(int o=0;o<(1<<k);o++){
		//cout<<o<<" "<<sl(o)<<"\n";
		ans=min(ans,sl(o));//cout<<ans<<" "<<endl;
	}
	cout<<ans;
	return 0;
}