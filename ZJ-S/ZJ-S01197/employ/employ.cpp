#include <bits/stdc++.h>
using namespace std;
int n,m,c[501],dp[501];
bool d[501],vis[501],f=1;
int die;
long long sum,asdf;
string s;
int main(){
	freopen("employ.in ","r",stdin);
	freopen("employ.out ","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		d[i]=s[i-1]-'0';
		if(!d[i]){
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			die++;
		}
	}
	if(!f){
		cout<<0;
	}else{
		sum=1;
		for(int i=1;i<=n-die;i++){
			sum=sum*i%998244353;
		}
		cout<<sum;
	}
	return 0;
}
