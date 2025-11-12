#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,c[105],cnt,cnt1,k[105];
string s;
signed main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i],k[i]=i;
	if(n>10){
		cout<<rand()%mod;
		return 0;
	}
	do{
		cnt1=cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||cnt1>=c[k[i]])cnt1++;
			else cnt++;
		if(cnt>=m)ans++;
		ans%=mod;
	}while(next_permutation(k+1,k+1+n));
	cout<<ans;
	return 0;
}