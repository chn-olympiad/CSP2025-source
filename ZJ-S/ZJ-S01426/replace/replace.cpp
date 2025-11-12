#include<bits/stdc++.h>
using namespace std;
string s[200002][2],t[2];
int n,q,dp[200002],k[200002];
bool ju(int j,int i){
	for(int p=0;p<s[j][0].size();p++){
		if(t[0][i-p]!=s[j][0][s[j][0].size()-1-p])return 0;
		if(t[1][i-p]!=s[j][1][s[j][0].size()-1-p])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t[0]>>t[1];
		bool v=1;
		if(t[0][0]==t[1][0])dp[0]=1;
		else dp[0]=0;
		for(int i=1;i<t[0].size()+1;i++)if(i&&t[0][i]==t[1][i])dp[i]+=dp[i-1];else v=0;
		for(int i=1;i<=t[0].size();i++){
			if(i&&t[0][i]==t[1][i])dp[i]=dp[i-1];
			for(int j=0;j<n;j++){
				if(s[j][0].size()<i+1&&k[j]==0 &&ju(j,i-1)){
					dp[i]+=dp[i-s[j][0].size()];
					k[j]=1;
				}
			}
		}cout<<dp[t[0].size()]-v<<endl;
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
