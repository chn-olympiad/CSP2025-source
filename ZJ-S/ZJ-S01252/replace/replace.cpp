#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string s[N],t[N];
void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		s[i]=" "+s[i];
		t[i]=" "+t[i];
	}
	while(q--){
		string tmp,st2;
		cin>>tmp>>st2;
		tmp=" "+tmp;st2=" "+st2;
		int ans=0;
		for(int i=1;i<=n;i++){
			string st1=tmp;
			string f=s[i].substr(1);
			string r=t[i].substr(1);
			if(st1.find(f)!=string::npos){
				int pos=st1.find(f);
				st1=" "+st1.substr(1,pos-1)+r+st1.substr(pos+s[i].size()-1);
				if(st1==st2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
