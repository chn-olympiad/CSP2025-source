#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
char s[N];
int k=1,t,a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++) if(s[i]>='0'&&s[i]<='9') a[k]=(int)(s[i])-48,k++;
	k--;
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--) cout<<a[i];
	return 0;
}
