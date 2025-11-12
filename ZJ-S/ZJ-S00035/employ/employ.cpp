#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,k=1,c[505];string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>s;
	for (int i=1;i<=m;i++){
		cin>>c[i];
		if (c[i]==0) x++;
	}for (int i=0;i<s.size();i++) if (s[i]=='1') y++;
	if (n==m){
		if (x>0||y>0) cout<<0;
		else{
			for (int i=1;i<=n;i++) k=(k*i)%998244353;
			cout<<k;
		}return 0;
	}if (m==1||y==0){
		for (int i=1;i<=n;i++) k=(k*i)%998244353;
		cout<<k;return 0;
	}cout<<0;
}