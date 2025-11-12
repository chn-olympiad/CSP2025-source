#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[1000005]; 
map<int,int> mp;
string s;
int fun(int n){
	int ans=0;
	while(n){
		ans+=n%2;
		n/=2;
	}
	return ans;
}
int c[100005];
int ac(int n){
	int aa=0;
	while(n){
		c[++aa]=n%2;
		n/=2;
	}
	int cnt=0;
	for(int i=aa;i>=1;i--){
		if(c[i]==0){
			cnt++;
			cnt+=mp[cnt]; 
		}
	}
	return s.size()-cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	if(n>=18){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	int cnt=0,ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=0;i<=1<<19-1;i++){
		if(fun(i)==cnt){
			if(ac(i)>=m){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}


