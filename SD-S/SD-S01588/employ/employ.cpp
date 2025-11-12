#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353;
string s1;
int n,m;
int ans=0;
int a[1000005];
bool fl[1000005];
bool check(vector<int>s){
	int sum=0;
	int f=0;
	for(int i=0;i<n;i++){
		if(f>=s[i] or s1[i]=='0'){
			f++;
		}
		else{
			sum++;
		}
	}
	if(sum>=m)return 1;
	return 0;
}
void dfs(vector<int>s){
	if(s.size()==n){
		if(check(s)){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!fl[i]){
			fl[i]=1;
			vector<int>k=s;
			k.push_back(a[i]);
			dfs(k);
			fl[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=0;i<s1.length();i++){
			if(s1[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
	vector<int>k1;
	dfs(k1);
	cout<<ans<<endl;
	return 0;
}

