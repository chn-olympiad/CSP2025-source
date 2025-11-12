#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],b[5005],c[5005]={1,1,0},j[5005]={1,1,0},inv[5005]={1,1,0},ans,s,k,x,t,p=998244353;
int mx(int x,int y){
	if(x>y)return x;
	return y;
}
int C(int x,int y){
	return j[y]*c[x]%p*c[y-x]%p;
}
void dfs(int d){
	if(d>n){
		s=0,k=0;x=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				k++;
				s+=a[i];
				x=mx(x,a[i]);
			}
		}
		if(k>=3&&s>2*x)ans++;
		return ;
	}else{
		for(int i=0;i<=1;i++){
			b[d]=i;
			dfs(d+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=mx(t,a[i]);
	}
	if(n<=20){
		dfs(1);
		cout<<ans;	
	}else{
		for(int i=2;i<=5000;i++){
			j[i]=j[i-1]*i%p;
			inv[i]=(p-p/i)*inv[p%i]%p;
			c[i]=c[i-1]*inv[i]%p;
		}
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
			ans%=p;
		}
		cout<<ans;
	}
	return 0;
}
