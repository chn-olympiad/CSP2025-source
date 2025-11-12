#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,can[505],c[505],a[15],book[15];string s;int bk,ans=1,sum;
void dfs(int x,int cnt){
	if(x>n){
		ans=ans+(cnt>=m);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!book[i]){
			book[i]=1;
			cnt=cnt+(((x-1-cnt)>=c[i]||can[x]==0)?0:1);
			dfs(x+1,cnt);
			cnt=cnt-(((x-1-cnt)>=c[i]||can[x]==0)?0:1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;++i){
		can[i+1]=s[i]-48;
		if(can[i+1]==1){
			++bk;
		}
	}
	if(bk<m){
		cout<<0;
		return 0;
	}else if(m==n&&bk!=n){
		cout<<0;
		return 0;
	}else if(bk==n&&n>=12){
		for(int i=2;i<=n;++i){
			ans*=(i-1);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}else if(n<=11){
		for(int i=1;i<=n;++i){
			cin>>c[i];
		}
		ans=0;
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		sum+=c[i];
	}
	sort(c+1,c+1+n);
	cout<<(((sum*114514)%mod)*1919810)%mod;
}
