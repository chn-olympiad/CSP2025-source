#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
const int MOD=998244353;
int a[323232],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	bool flag=0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='0') flag=1;
		if(s[i]=='0'&&m==1) ans++;
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	if(!flag){
		ans=1;
		while(n--){
			ans*=2;
			while(ans>=MOD) ans-=MOD;
		}
		cout<<ans;
	}
	if(n<=20){
		ans=0;
		vector<int> k;
		for(int i=1;i<=n;i++) k.push_back(i);
		while(next_permutation(k.begin(),k.end())){
			int g=0,l=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1') l++;
				else if(a[i]<l) continue;
				else g++;
			}
			if(g>=m) ans++;
		}
		cout<<ans;
	}
	return 0;
} 
