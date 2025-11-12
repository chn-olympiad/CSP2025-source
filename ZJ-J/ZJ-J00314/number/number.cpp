#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int i,l,f[N];char s[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s+1;l=strlen(s+1);
	for(i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9')
			f[s[i]-48]++;
	}
	for(i=9;i>=0;i--)
		while(f[i]>0)f[i]--,cout<<i;
	return 0;
}
//8:40   tongguoyangli1--4