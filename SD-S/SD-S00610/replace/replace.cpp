#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,q;
unordered_map<string,string> mp;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		string a;
		cin>>a>>b;
		int ans=0;
		for(auto i:mp){
			int p=a.find(i.first);
			if(p!=-1){
				string t=a;
				t.replace(p,i.second.size(),i.second);
				if(t==b) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

