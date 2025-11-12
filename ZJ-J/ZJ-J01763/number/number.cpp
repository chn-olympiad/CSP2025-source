#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],len;
string s;
bool cmp(ll x,ll y){return x>y;}
int main(){
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++len]=s[i]-'0';
	sort(a+1,a+1+len,cmp);
	if(a[1]==0) cout<<0;
	else for(ll i=1;i<=len;i++) cout<<a[i];
	cout<<"\n";
	return 0;
}