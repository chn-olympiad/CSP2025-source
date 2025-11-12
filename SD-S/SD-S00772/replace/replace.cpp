#include<bits/stdc++.h>
using namespace std;
string s1[10005],s2[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string s,t;cin>>s>>t;int ans=0;
		for(int i=1;i<=n;i++){
			int k=s.find(s1[i]);
			if(k==-1)continue;
			string p=s; 
			for(int j=k;j<=k+s1[i].length()-1;j++)p[j]=s2[i][j-k];
			if(p==t)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

