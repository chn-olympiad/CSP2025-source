#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int a[N],n=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)cout<<a[i];
	return 0;
}
