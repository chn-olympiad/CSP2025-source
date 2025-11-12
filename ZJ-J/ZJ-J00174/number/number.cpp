#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10],S;
string s,ans;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++,S++;
	}
	for(int i=9;i>=0;i--)
		while(a[i]--)
			cout<<i;
	cout<<ans;
	return 0;
}
