#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
const int mod=998244353;
int n,m;
bool a[MAXN];
struct node{
	int j,val;
	bool operator < (const node &r)const{
		return j<r.j;
	}
};
node c[MAXN];
bool check(){
	int fail=0;
	for(int i=1;i<=n;i++){
		if(a[i]==false||fail>=c[i].val)
			fail++;
	}
	if(n-fail>=m)
		return true;
	return false;
}
int getp(int x){
	int ans=1;
	for(int i=2;i<=x;i++)
		ans=ans*i%mod;
	return ans; 
}
bool all1=true;
int cnt0=0;
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='1')
			a[i]=true;
		else{
			a[i]=false;
			all1=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i].val;
		c[i].j=i;
		if(c[i].val==0)
			cnt0++;
	}
	if(all1){
		if(n-cnt0<m){
			cout<<0;
			return 0;
		}
		cout<<getp(n)%mod;
	}
	else{
		int ans=0;
		if(check())ans++;
		while(next_permutation(c+1,c+1+n)){
			if(check())ans++;
		}
		cout<<ans%mod;	
	}
	return 0;
}
