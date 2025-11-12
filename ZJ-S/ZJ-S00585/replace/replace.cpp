#include<bits/stdc++.h>
using namespace std;
long long n,q,nxt[1005][3][2005],suml;
string s[200005][3],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int k=1;k<=n;++k){
		cin>>s[k][1]>>s[k][2];
		s[k][1]=" "+s[k][1];
		s[k][2]=" "+s[k][2];
		for(int i=2,j=0;i<s[k][1].size();++i){
			while(j && s[k][1][i]!=s[k][1][j+1]) j=nxt[k][1][j];
			if(s[k][1][i]==s[k][1][j+1])++j;
			nxt[k][1][i]=j;
		}
		for(int i=2,j=0;i<s[k][1].size();++i){
			while(j && s[k][2][i]!=s[k][2][j+1]) j=nxt[k][2][j];
			if(s[k][2][i]==s[k][2][j+1])++j;
			nxt[k][2][i]=j;
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int f1=l,f2=1;
		for(int i=1;i<=l;++i){
			if(t1[i]!=t2[i]){
				f1=i;
				break;
			}
		}
		for(int i=l;i>=1;--i){
			if(t1[i]!=t2[i]){
				f2=i;
				break;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1,now1=0,now2=0;j<=l;++j){
				while(now1 && t1[j]!=s[i][1][now1+1]) now1=nxt[i][1][now1];
				while(now2 && t2[j]!=s[i][2][now2+1]) now2=nxt[i][2][now2];
				if(t1[j]==s[i][1][now1+1]) ++now1;
				if(t2[j]==s[i][2][now2+1])++now2;
				if(j-s[i][1].size()+2<=f1 && j>=f2 && now1==now2 && now1==s[i][1].size()-1) ++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
