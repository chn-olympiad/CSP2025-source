#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string s;
			int t=t1.find(s1[i]);
			while(t!=-1){
				s=t1;
				for(int j=t;j<=t+s1[i].size()-1;j++){
					s[j]=s2[i][j-t];
				}
				t=t1.find(s1[i],t+1);
				if(s==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
