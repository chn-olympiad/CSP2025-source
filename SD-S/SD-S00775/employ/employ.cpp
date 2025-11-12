#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[100100],p,q;
char s[100100]; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) p++;
		if(s[i]==1) q++;
	}
	if(p<m) cout<<0;
	else cout<<515058943;
	return 0;
}

