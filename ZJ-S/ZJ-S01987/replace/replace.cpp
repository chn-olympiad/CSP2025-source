#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int n,q,t,ans;
string s1,s2,s3,s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>s1>>s2;
		ans=0;
		for(int i=1;i<=n;i++){
			t=s1.find(s[i][0]);
			if(t==-1)continue;
			s3=s1;
			for(int j=t;j<=t+s[i][0].size()-1;j++){
				s3[j]=s[i][1][j-t];
			}
			if(s3==s2)ans++;
		}
		cout<<ans<<"\n";
		 
	}
	return 0;
}
