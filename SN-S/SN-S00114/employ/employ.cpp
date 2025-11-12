//吴泊成 SN-S00114 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,s[505],c[505],l=1,a=1,ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long i=1,j=n;i<=n;i++,j--){
		l*=j;
	}
	for(long long i=1,j=n;i<=m;i++,j--){
		a*=j;
	}
	ans=a*l;
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
