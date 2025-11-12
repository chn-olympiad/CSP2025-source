#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+20;
string P[maxx],S[maxx];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>P[i]>>S[i];
	}
	for(int i=1;i<=q;i++){
		string s1,s2;cin>>s1>>s2;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s1.find(P[j])!=-1){
				int sz=P[j].size(),sz1=s1.size(),pos=s1.find(P[j]);
				string sum="";
				for(int k=0;k<pos;k++)sum+=s1[k];
				sum+=S[j];
				for(int k=pos+sz;k<sz1;k++)sum+=s1[k];
				if(sum==s2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}