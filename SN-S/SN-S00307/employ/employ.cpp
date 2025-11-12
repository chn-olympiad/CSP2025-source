#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100086];
string s;
int jc(int f){
	int cnt=1;
	for(int i=2;i<=f;i++) cnt=cnt*i%998244353;
	return cnt%998244353;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int k=0;
		while(s[++k]!='1');
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]>k){
				i=n-i+1;
				cout<<jc(i);
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++) if(s[i]=='0'){
			cout<<0;
			return 0;
		}
	}
	cout<<jc(n);
	return 0;
}
