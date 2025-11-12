#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],p[505],a[505],used[505],ans;
void dg(int x){
	if(x==n+1){
		int t=0;
		for(int i=1;i<=n;i++){
			if(t>=p[a[i]]){
				t++;
				continue;
			}
			if(!c[i])t++;
		}
		int tt=n-t;
		if(tt>=m){
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(a[x]=1;a[x]<=n;a[x]++){
		if(!used[a[x]]){
			used[a[x]]=1;
			dg(x+1);
			used[a[x]]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool isA=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int sl=s.size();
	for(int i=0;i<sl;i++){
		if(s[i]!='1')isA=0;
		if(s[i]=='1')c[i+1]=1;
		else c[i+1]=0;
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	if(isA){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=(long long)(ans*i);
			ans%=mod;
		}
		return 0;
	}
	if(n<=18){
		dg(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
