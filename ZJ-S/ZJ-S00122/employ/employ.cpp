#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],f[505],fc[505],sum[505],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<s.size();i++){
		f[i+1]=s[i]-'0';
		sum[i+1]=sum[i]+f[i+1];
	}
	ans=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) ans*=c[i];
		fc[i]=1;
	}
	if(sum[n]<m){
		printf("0");
		return 0;
	}
	printf("%d",ans);
	return 0;
}