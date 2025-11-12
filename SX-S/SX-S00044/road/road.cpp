#include<bits/stdc++.h>
#define ll long long
#define fi fisrt
#define se second
#define pi pair
//recaint.cpp
//#define int bong bong

using namespace std;
const int N=200005;
const ll inf=1e18;
int n,m,k,fa[N];
int fd(int x){
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}
struct road{
	int x,y,z,t;
	friend bool operator<(const road &a,const road &b){
		return a.z<b.z;
	}
}a[N*6];
int c[11];
vector<road>v;
ll sol(int S,ll lim){
	ll res=0,cnt=0,t=0;
	for(int i=1;i<=k;i++)if((1<<(i-1))&S)res+=c[i],t++;
	
	if(res>lim)return res;
	//cout<<res<<" "<<S<<endl;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(auto p:v){
		if(res>lim)return res;
		if(p.t&&(!((1<<(p.t-1))&S)))continue;
		int x=fd(p.x);
		int y=fd(p.y);
		if(x==y)continue;
		res+=p.z;
		//cout<<p.x<<" "<<p.y<<" "<<p.z<<" "<<p.t<<" "<<endl;
		fa[x]=y;
		cnt++;
		if(cnt==n+t-1)break;
	}
	// cout<<cnt<<" "<<res<<" "<<S<<endl;
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll st=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;

	ll cnt=0,res=0;
	for(int i=1;i<=m;i++){
		int x=fd(a[i].x);
		int y=fd(a[i].y);
		if(x==y)continue;
		res+=a[i].z;
		fa[x]=y;
		cnt++;
		v.push_back(a[i]);
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;
			v.push_back({n+i,j,x,i});
		}
	}
	sort(v.begin(),v.end());
	for(int S=1;S<(1<<k);S++)res=min(res,sol(S,res));
	cout<<res<<endl;
	return 0;
}