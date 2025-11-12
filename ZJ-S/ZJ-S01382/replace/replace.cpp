#include<bits/stdc++.h>
using namespace std;
string s[100010][2];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s[i][0]>>s[i][1];		
	while(q--){
		string t,t1;
		cin>>t>>t1;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j+s[i][0].size()-1<t.size();j++){
				string g="";
				for(int k=j;k<j+s[i][0].size();k++)
					g=g+t[k];
				if(g==s[i][0]){
					string r=t;
					for(int k=j,k1=0;k<j+s[i][0].size();k++,k1++)
						r[k]=s[i][1][k1];
					if(r==t1)	ans++;
				}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
//60+48+40+10=158pts.
