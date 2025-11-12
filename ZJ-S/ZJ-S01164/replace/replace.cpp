#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans;
string s1[200010],s2[200010],ss1,ss2,sss1,sss2,sss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++){
		cin>>ss1>>ss2;ans=0;
		for(int j=1;j<=n;j++){
			sss1=ss1;sss2=ss2;
			x=sss1.find(s1[j]);
			if(x!=string::npos){
				sss1.erase(x,s1[j].size());
				sss=sss1.substr(x);
				sss1.erase(x);
				sss1+=s2[j];sss1+=sss;
				if(sss1==sss2)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}