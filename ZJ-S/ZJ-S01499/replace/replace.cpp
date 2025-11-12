#include<bits/stdc++.h>
using namespace std;
unordered_map<string,unordered_map<string,int>>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		mp[s][t]++;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int ls=s.size();
		int lt=t.size();
		string S="",T="";
		string P1="";
		string P2="";
		string K1="";
		string K2="";
		int ans=0;
		for(int i=0;i<ls;i++){
			S="";
			T="";
			for(int j=i;j<ls;j++){
				S+=s[j];
				T+=t[j];
				if(P1!=P2)break;
				K1="",K2="";
				for(int k=j+1;k<ls;k++){
					K1+=s[k];
					K2+=t[k];
				}
				if(K1!=K2)continue;
				ans+=mp[S][T];
			}
			P1+=s[i];
			P2+=t[i];
			
		}
		cout<<ans<<"\n";
	}
}