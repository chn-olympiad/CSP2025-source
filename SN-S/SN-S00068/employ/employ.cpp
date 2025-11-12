#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[505],p[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='s'+s;
	for(int i=1;i<=n;i++)
		cin>>c[i],p[i]=i;
	int ans=0;
	do{
		int sum=0,last=0;
		for(int i=1;i<=n;i++){
			if(last>=c[p[i]]) last++;
			else if(s[i]=='0') last++;
			else sum++;
		}
		if(sum>=m) ans=(ans+1)%998244353;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
