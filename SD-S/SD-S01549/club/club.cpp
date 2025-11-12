#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,c,a[N],t[4],b[N][4],ans,f[N];
void dfs(ll x){
	if(x==n+1){
		memset(t,0,sizeof(t));
		ll sum=0;
		for(ll i=1;i<=n;i++){
			t[a[i]]++;
		}
		for(ll i=1;i<=3;i++){
			if(t[i]>c){
				return;
			}
		}
		for(ll i=1;i<=n;i++){
			sum+=b[i][a[i]];
		}
		ans=max(ans,sum);
		return;
	}
	for(ll i=1;i<=3;i++){
		a[x]=i;
		dfs(x+1);
	}
}
void solve2(){
	dfs(1);
	cout<<ans<<endl;	
}
void solve1(){
	ans=0;
	sort(f+1,f+n+1);
	ll cnt=1;
	for(ll i=n;i>=1&&cnt<=c;i--,cnt++){
		ans+=f[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		ans=0;
		c=0;
		cin>>n;
		c=n/2;
		bool flag=0;
		for(ll i=1;i<=n;i++){
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			f[i]=b[i][1];
			if(b[i][2]!=0||b[i][3]!=0){
				flag=1;
			}
		}
		if(flag==0) solve1();
		else solve2();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

*/
