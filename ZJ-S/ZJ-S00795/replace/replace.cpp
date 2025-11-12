#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 200005
int n,q,nxt[N][N],cnt[N];
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=s1[i];s2[i]=s2[i];
	}
	for(int i=1;i<=n;i++){
		nxt[i][1]=0;
		for(int j=2,k=0;j<=s1[i].length();j++){
			while(k&&s1[i][j]!=s1[i][k+1])k=nxt[i][k];
			if(s1[i][j]==s1[i][k+1])k++;
			nxt[i][j]=k;
		}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=1,k=0;j<=t1.length();j++){
				while(k&&t1[j]!=s1[i][k+1])k=nxt[i][k];
				if(t1[j]==s1[i][k+1])k++;
				if(k==s1[i].length()||nxt[i][j]==k)cnt[i]++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.find(s1[i])!=-1){
				int pos=t1.find(s1[i]);
				string ss;
				ss=t1[0]+t1.substr(1,pos-1)+s2[i]+t1.substr(pos+s2[i].length(),t1.length());
				if(ss==t2)ans+=cnt[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
