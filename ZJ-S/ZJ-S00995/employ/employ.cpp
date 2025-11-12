#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p[510],f,c[510],ans;
char s[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	do{
		f=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=f)++f;
			else if(s[i]=='0')++f;
			if(n-f<m)break;
		}
		if(n-f>=m)++ans;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
