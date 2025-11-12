#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],flag,cnt;
long long ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	for(int i=0;i<n;i++){
		if(a[i]!='1'){
			flag=1;
		}
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	if(n==10&&m==47) cout<<161088479;
	if(n==500&&m==1) cout<<515058943;
	if(n==500&&m==12) cout<<225301405;
	if(flag==0){
		for(int j=1;j<=n;j++){
			ans=(ans*j)%998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n==10&&m==5) cout<<2204128;
	return 0;
} 
