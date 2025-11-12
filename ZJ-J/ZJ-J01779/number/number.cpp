#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
string s;
int a[210];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--) if(a[i]) for(int j=1;j<=a[i];j++) printf("%d",i);
	return 0;
}
