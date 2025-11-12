#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int cnt,ans=1;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=cnt;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
