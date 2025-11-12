#include<bits/stdc++.h>
using namespace std;
int n,q,max_size;
string s[200005],s1[200005];
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
		max_size=max(max_size,(int)(s[i].size()));
		mp[s[i]]=s1[i];
		mp[s1[i]]=s[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<"0\n";
		else {
			int ans=0;
			for(int i=1;i<=n;i++){
				string o="",p="";
				for(int j=0;j+s[i].size()-1<t1.size();j++){
					string x="",y="";
					for(int k=1;k<=s[i].size();k++){
						x=x+t1[j+k-1];y=y+t2[j+k-1];
					}
					if(x==s[i]&&y==mp[s[i]]){
						if(o!=p)continue;
						string z="",zz="";
						for(int k=t1.size()-1;k>j+s[i].size()-1;k--){
							z=t1[k]+z;
							zz=t2[k]+zz;
						}
						if(z==zz){
							ans++;
						}
					}
					o=o+t1[j];p=p+t2[j];
				}
			}
			cout<<ans<<endl;
		}
	}
}//4 2 xabcx xadex ab cd bc de aa bb xabcx xadex aaaa bbbb