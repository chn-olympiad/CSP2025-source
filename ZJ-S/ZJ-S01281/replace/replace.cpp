#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		cin>>mp[s];
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		string v;
		for(int i=0;i<s1.size();i++){
			string p;
			for(int j=i;j<s1.size();j++){
				char ch=s1[j];
				p+=ch;
				string k=mp[p];
				for(int g=j+1;g<s1.size();g++){
					k+=s1[g];
				}
				k=v+k;
				if(k==s2){
					ans++;
				}
			}
			v+=s1[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
