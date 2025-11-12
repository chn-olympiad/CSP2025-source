#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q;
string s1[200005],s2[200005],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				if(t1.substr(0,i)!=t2.substr(0,i)){
					continue;
				}else if(j!=t1.size()-1 && t1.substr(j+1)!=t2.substr(j+1)){
					continue;
				}else{
					string t3=t1.substr(i,j-i+1),t4=t2.substr(i,j-i+1);
					for(int i=1;i<=n;i++){
						if(t3==s1[i] && t4==s2[i])ans++;
					}
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
} 