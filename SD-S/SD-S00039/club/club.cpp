#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll s=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*k;
} 

const int N=1e5+5;
int n;
ll ans,a[N][3],b[N];
vector<int>vec[3];

void solve(int T){
	sort(vec[T].begin(),vec[T].end(),[&](int x,int y){
		return b[x]>b[y];
	});
	while(vec[T].size()>n/2){
		int x=vec[T].back();
		ans-=b[x];
		vec[T].pop_back();
	}
}

void solve(){
	n=read();
	for(int i=0;i<3;i++) vec[i].clear();
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) a[i][j]=read();
		int mx=max_element(a[i],a[i]+3)-a[i];
		ans+=a[i][mx]; vec[mx].push_back(i);
		ll cmx=0;
		for(int j=0;j<3;j++)
			if(j!=mx) cmx=max(cmx,a[i][j]);
		b[i]=a[i][mx]-cmx;
	}
	for(int i=0;i<3;i++)
		if(vec[i].size()>n/2){
			solve(i);
			break;	
		}
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
