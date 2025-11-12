#include<bits/stdc++.h>
using namespace std;
map <string,string> mp;
string s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		s[i]=s1;
	}
	for (int i=1;i<=q;i++){
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=t1.size();
		for (int j=1;j<=n;j++){
			int pos=t1.find(s[j]);
			if (pos>=0){
				if (t1.substr(0,pos)+mp[s[j]]+t1.substr(pos+s[j].size(),len-pos-s[j].size()+1)==t2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
