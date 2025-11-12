#include<bits/stdc++.h>
using namespace std;
string s,cnt;
int ans=0;
map<int,int>mp;
long long a[1000005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<=9&&s[i]>=0){
			int t=s[i]-'0';
			mp[t]++;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(mp[i]!=0){
			for(int j=0;j<mp[i];j++){
				cout<<mp[i];
			}
		}
	}
	return 0;
}

