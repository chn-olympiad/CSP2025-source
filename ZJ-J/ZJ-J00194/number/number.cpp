#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[1000010],t;
char s[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s+1;n=strlen(s+1);
	for(i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	}
	sort(a+1,a+1+t);
	for(i=t;i>=1;i--) cout<<a[i];
	return 0;
}
