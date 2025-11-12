#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
char a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll l=s.size();
	ll k=0;
	for(ll i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')a[++k]=s[i];
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
} //#Shang4Shan3Ruo6Shui4
