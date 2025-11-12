#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,js,ans;
int a[505];
string s;
map<int,int>cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]==n){
		for(int i=0;i<s.size();i++){
			if(s[i]==0){
				js=i;
				break;
			}
		}
		if(js+1<m) cout << 0;
		else{
			for(int i=n;i>=2;i--){
				ans=ans*i%mod;
			}
			cout << ans;
		}
	}
	return 0;
}