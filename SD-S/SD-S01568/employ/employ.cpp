#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
string s;
int n,m,c[N],p[N],vis[N];
long long ans;
void solve0(){
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		for(int i=1;i<=n;i++)
			vis[i]=0;
		vis[0]=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')
				continue;
			for(int j=1;j<=min(i,c[p[i]]);j++)
				if(vis[i-j]){
					vis[i]=1;
					break;
				}
			if(vis[i])
				cnt++;
		}
		if(cnt>=m)
			ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
}
void solve1(){
	
}
void solve2(){
	
}
void solve3(){
	int minn=1e9;
	for(int i=1;i<=n;i++)
		minn=min(minn,c[i]);
	if(minn==0)
		cout<<0<<endl;
	else{
		long long res=1;
		for(int i=1;i<=n;i++)
			res=res*i%mod;
		cout<<res<<endl;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==n){
		solve3();
		return 0;
	}
	else
		solve0();
	return 0;
}
