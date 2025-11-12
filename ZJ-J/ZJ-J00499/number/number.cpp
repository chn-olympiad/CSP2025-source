#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10010];char a[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;int n=strlen(a+1);
	for(int i=1;i<=n;i++)
		if('0'<=a[i]&&a[i]<='9')
			f[a[i]]++;
	for(char c='9';c>='0';c--)
		while(f[c]--)
			cout<<c;
	return 0;
}
