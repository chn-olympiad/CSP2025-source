#include<bits/stdc++.h>
using namespace std;
int n,m,c[1005];
char s[1005];
long long ksm(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*(n%998244353))%998244353;
	}
	return ans;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++; 
	}
	if(n==m){
		cout<<ksm(n-cnt)<<endl;
	}
	return 0;
}