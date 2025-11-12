#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
string s,m[200]={""},ans="";
int n;

signed main(){
	FI("number");
	FO("number");
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		char x=s[i];
		int tmp=x-'0';
		if(!(tmp<=9 && tmp>=0)) continue;
		m[tmp]+=x;
	}
	for(int i=9;i>=0;i--){
		if(m[i]!="") ans+=m[i];
	}
	cout<<ans;
	return 0;
}
