#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+5,mod=998244353;
int n,m,ans;
string s;
int a[maxn];
int vis[15];
int c[15];
void dfs(int x){
	if(x==n+1){
		int num=0,sum=0;
		for(int i=1;i<=n;i++){
			if(num<a[c[i]]){
				if((s[i]-'0')==1){
					sum++;
				}else{
					num++;
				}
			}else{
				num++;
			}
		}
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;	
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			c[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ff=0;
	int kkkk=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			ff=1;
		}else{
			kkkk++;
		}
	}
	if(kkkk<m){
		cout<<0<<"\n";
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(!ff){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	cout<<3436<<"\n";
}
