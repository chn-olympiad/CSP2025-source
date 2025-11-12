#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+15;
char s[maxn];
int a[maxn],len,tot;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>(s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
}
