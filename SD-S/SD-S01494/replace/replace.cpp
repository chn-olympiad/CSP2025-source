#include<bits/stdc++.h>
using namespace std;
string l1,l2,s1[200000],s2[100000];int bn[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	int b1=-1,b2=-1;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=1;j<=s1[i].size();j++){
			if(s1[i][j]='b') b1=i;
			if(s2[i][j]='b') b2=i;
		}
		bn[i]=b1-b2;
	}
	while(q--){
		cin>>l1>>l2;
		if(l1.size()!=l2.size()){
			cout<<0;
			continue;
		}
		bool f=0;int b1=-1,b2=-1;
		for(int i=0;i<=n;i++){
			if(l1[i]='b') b1=i;
			if(l2[i]='b') b2=i;
		}
		int bns=b1-b2;int ans=0;
		for(int i=1;i<=n;i++){
			if(bns==bn[i]) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
