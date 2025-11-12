#include<bits/stdc++.h>
#define int long long
using namespace std;
const int has=131,mod=1e9+7;
int n,q;
string s[200005][2];
unordered_map<int,int> mp;
int pw[5000005];
int Hash(string s){
	int ans=0;
	for(int i=0;i<s.size();i++)ans=(ans*has%mod+s[i])%mod;
	return ans;
}
int sum[5000005][2];
int get(int l,int r,bool p){
	if(r<l)return 0;
	return (sum[r][p]-sum[l-1][p]*pw[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1],mp[Hash(s[i][0])]=Hash(s[i][1]);
	pw[0]=1;
	for(int i=1;i<=5e6;i++)pw[i]=pw[i-1]*has%mod; 
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		s1=" "+s1,s2=" "+s2;
		for(int i=1;i<s1.size();i++)sum[i][0]=(sum[i-1][0]*has%mod+s1[i])%mod;
		for(int i=1;i<s2.size();i++)sum[i][1]=(sum[i-1][1]*has%mod+s2[i])%mod;
		int cnt=0;
		for(int i=1;i<s1.size();i++){
			for(int j=1;j<=i;j++){
				if(mp.count(get(j,i,0))&&mp[get(j,i,0)]==get(j,i,1)&&(get(1,j-1,0)==get(1,j-1,1)||j==1)&&(get(i+1,s1.size()-1,0)==get(i+1,s2.size()-1,1)||i==s1.size()-1)){
					//cout<<j<<","<<i<<"\n";
					cnt++;
				}
				//if(!((get(1,j-1,0)==get(1,j-1,1)||j==1)&&(get(i+1,s1.size()-1,0)==get(i+1,s2.size()-1,1)||i==s1.size()-1)))break;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
1 1
xabcx xadex
xabcx xadex
*/
