#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],mod=998244353,num,sum,flg,ans=1;
char s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0' && flg==0){
			num++;
		}if(s[i]=='1'){
			flg=1;
		}
	}for(int i=1;i<=n;i++){
		cin>>c[i]; 
		if(c[i]>=num) sum++;
	}
	for(int i=sum;i>=1;i--){
		ans=(i%mod)*ans%mod;
	}
	cout<<ans;
	return 0;
}
//T4 only 10tps QAQ
//bao diao le  WWWWWWW
//wan la
