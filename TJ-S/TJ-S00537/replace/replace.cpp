#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string u,v;
		cin>>u>>v;
		int ans=0;
		for(int i=1;i<=n;i++){
			int fu=u.find(s1[i]);
			if(fu==-1)continue;
			int fv=v.find(s2[i]);
			if(fu==fv){
				bool gh=true;
				for(int j=0;j<=u.size();j++){
					if(j==fu){
						j+=s1[i].size();
						j--;
						continue;
					}
					if(u[j]!=v[j]){
						gh=false;
						break;
					}
				}
				if(gh){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
