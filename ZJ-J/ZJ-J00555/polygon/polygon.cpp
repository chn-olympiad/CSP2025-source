#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long dp[5050][5050];
int n;
long long ans=0;
long long a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];i++) dp[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=5000;j++){
			if(a[i]>j) dp[i][j]=(dp[i-1][j]+dp[i-1][0]+1)%MOD;
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%MOD;
		}
	}
	for(int i=3;i<=n;i++){
		ans+=dp[i-1][a[i]];
		ans%=MOD;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
i am a chuyi juruo
i want to say
i ac all big data at 9:36
from 8:30 to 9:36!!! about 67 mins
hexiaoyan is my classmate
he is better than me(maybe)
so please guanzhu him
hzc0829 JCJ57999 are also my classmates
they are good
CSP-J is the most important part of my oi life
hope i can do better in the future 
*/
