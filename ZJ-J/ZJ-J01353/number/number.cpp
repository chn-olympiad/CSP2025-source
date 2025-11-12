#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll> f;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9' && s[i]>='0'){
			ll st=s[i]-'0';
			f.push_back(st);
		}
	}
	sort(f.begin(),f.end(),greater<ll>());
	for(int i=0;i<f.size();++i){
		ans+=(char)(f[i]+'0');
	}
	cout<<ans<<endl;
	return 0;
}