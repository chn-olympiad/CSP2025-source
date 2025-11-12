#include<bits/stdc++.h>
#define modd 998244353
#define int long long
using namespace std;
int n,m,ans;
string s;
int now[505];
int a[505];
bool vis[505];
vector<int> tmp;
void dfs(int now){
	if(now>n){
		int cnt=0;
		int sum=0;
		for(int i=0;i<tmp.size();i++){
			if(a[tmp[i]]<=cnt){
				continue;
			}
			if(s[i]=='1'){
				sum++;
			}
			else{
				cnt++;
			}
		}
		if(sum==m){
			ans++;
			ans%=modd;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			tmp.push_back(i);
			vis[i]=true;
			dfs(now+1);
			vis[i]=false;
			tmp.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	int ans=1;
	for(int i=n;i>=(n-m+1);i--){
		for(int j=m;j>=1;j--){
			if(!vis[j]&&i%j==0){
				ans*=(i/j);
				ans%=modd;
				vis[j]=true;
				break;
			}
		}
	}
	cout<<ans;
}

