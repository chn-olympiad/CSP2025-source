#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map < string , int > len;
map <string, vector <string > > mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);///
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string s1,s2;
		cin>>s1>>s2;
		int l=s1.length();
		len[s1]=l;
		mp[s1].push_back(s2);
	}
	string mb1,mb2;
	while(q--) {
		ans=0;
		cin>>mb1>>mb2;
		int l=mb1.length(),ll=mb2.length();
		if(l!=ll) {
			cout<<0<<endl;
			continue;
		}
		for(auto i:mp) {
			string ss=i.first;
			int xb=mb1.find(ss);//-mb1
			//cout<<ss<<' '<<xb<<endl;
			if(xb==-1)continue;
			if(xb+len[ss]>l)continue;
			string s1=mb1.substr(0,xb),s2=mb1.substr(xb+len[ss],l-xb+len[ss]+1);
			for(auto j:i.second) {
				string sss=s1+j+s2;
				//cout<<sss<<endl;
				if(sss==mb2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
