#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=1e4+5;
int n,q;
string s1[maxn],s2[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string x,z;
			for(int j=s1[i].size();j<t1.size();j++)z+=t1[j];
			for(int j=0;j+s1[i].size()-1<t1.size();j++){
				if(t1.substr(j,s1[i].size())==s1[i]){
					if(x+s2[i]+z==t2)ans++;
		    	}
				x+=t1[j];
				z.erase(0,1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
