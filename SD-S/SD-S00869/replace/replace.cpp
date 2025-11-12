#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string s1[N],s2[N];
int s[N],vis[5000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b'){
				for(int i=1;i<=q;i++)  cout<<0<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b')  s[i]=j;
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b')  s[i]-=j;
		}
		vis[s[i]]++;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;int _=0;
		cin>>t1>>t2;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b')  _=j;
		}
		for(int j=0;j<t2.size();j++){
			if(t2[j]=='b')  _-=j;
		}
		cout<<vis[_]<<endl;
	}
	return 0;
}
