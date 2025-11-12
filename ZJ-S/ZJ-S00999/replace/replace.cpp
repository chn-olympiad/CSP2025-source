#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t[0]>>t[1];
		int len2=t[0].size(),l=len2-1,r=0,ans=0;
		for(int i=1;i<=n;i++){
			int len1=s[i][0].size();
			for(int j=0;j<len2;j++){
				if(j+len1>len2)continue;
				bool pd=1;
				for(int k=0;k<len1;k++)if(t[0][j+k]!=s[i][0][k]){pd=0;break;}
				if(pd){
					//cout<<t[0]<<" "<<s[i][0]<<"\n";
					bool PD=1;
					for(int k=0;k<len2;k++){
						char c;
						if(k>=j&&k<j+len1)c=s[i][1][k-j];
						else c=t[0][k];
						if(c!=t[1][k]){PD=0;break;}
					}
					if(PD)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}