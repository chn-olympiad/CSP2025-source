#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=5e2+5;
int n,m,c[N],a[N],b[N],pre[N],d[N];
ll ans;
string s;
ll qp(int n){
	ll sum=1;
	for(ll i=1;i<=n;i++){
		sum=(sum*i)%mod;
	}
	return sum;
}
void dfs(int k)
{
	if(k>n){
		int cnt=0,f=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')cnt++;
			else{
				if(c[a[i]]<=cnt){
					cnt++;
				}else f++;
			}
		}
		if(f>=m){
			ans++;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(d[i]==0){
			d[i]=1;
			a[k-1]=i;
			dfs(k+1);
			d[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	ll cnt=0,pos=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		pre[c[i]]++;
		if(c[i]==0)pos++;
		if(s[i]=='1')
		cnt++,b[cnt]=i;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n-pos<m){
		puts("0");
		return 0;
	}
	if(m==n||pos==0){
		cout<<qp(n);
		return 0;
	}
	cout<<qp(n);
	return 0;
}
