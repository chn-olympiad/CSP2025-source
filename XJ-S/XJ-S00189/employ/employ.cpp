#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int mod=998244353;
int m,n,c[N];char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int f1=0;bool fa=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1' && f1==0){
			f1=i;break;	
		}
		if(s[i]=='0')fa=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==1){
		sort(c+1,c+n+1);
		int x=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=f1)break;
			x++;
		}
		cout<<n-x;
	}
	if(m==n && fa==0)cout<<"0";
	if(fa){
		int ans=1;
		for(int i=1;i<=m;i++){
			ans*=(n-i+1);ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
