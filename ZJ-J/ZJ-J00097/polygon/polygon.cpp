#include<bits/stdc++.h>
using namespace std;
const int l=998244353;
typedef long long ll;
ll n,m,s,x,t,a[5005],v[5005];
void dfs(ll k,ll z,ll y){
	if(k==n+1){
		if(z>y*2)s++;
		return;
	}dfs(k+1,z+a[k],max(y,a[k]));
	dfs(k+1,z,y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}if(m==1){
		for(int i=1;i<=n;i++){
			t=n-i-1,x=1;
			for(int i=t;i>=1;i--){
				s+=i*x%l;
				x=(x*2)%l;
			}
		}cout<<s;
		return 0;
	}if(n<=20){
		dfs(1,0,0);
		cout<<s;
		return 0;
	}return 0;
}

