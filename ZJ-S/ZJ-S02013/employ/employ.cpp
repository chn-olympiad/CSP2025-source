#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)cnt++;
	}//all s[i]=1
	if(m>cnt){
		printf("0");
		return 0;
	}else{
		long long ans=1;
		for(int i=1;i<=cnt;i++){
			ans*=i;
			ans=ans%998224353;
		}
		printf("%lld",ans);
	}
	return 0;
}