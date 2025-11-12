#include<bits/stdc++.h>
using namespace std;
const long long mod1=1e9+7,mod2=998244353; 
int n,q,kmp[10005];
string s[10005],t[10005];
bool vis[10005],Vis[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
	  cin>>s[i]>>t[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			printf("0\n");
			continue;
		};
		int L=0,R=x.size()-1,ans=0;
		while(x[L]==y[L])L++;
		while(x[R]==y[R])R--;
		for(int i=1;i<=n;i++){
			if(s[i].size()>x.size())continue;
			for(int j=1;j<s[i].size();j++){
				int k=kmp[j-1];
				while(k&&s[i][j]!=s[i][k])k=kmp[k-1];
				if(s[i][j]==s[i][k])k++;
				kmp[j]=k;
			}
			int k=0;
			for(int l=0;l<x.size();l++){
				while(k&&s[i][k]!=x[l])k=kmp[k-1];
				if(x[l]==s[i][k])k++;
				if(k==s[i].size()){
					k=kmp[k];
					vis[l]=1;
				}
			};
			for(int j=1;j<t[i].size();j++){
				int k=kmp[j-1];
				while(k&&t[i][j]!=t[i][k])k=kmp[k-1];
				if(t[i][j]==t[i][k])k++;
				kmp[j]=k;
			}
			k=0;
			for(int l=0;l<y.size();l++){
				while(k&&t[i][k]!=y[l])k=kmp[k-1];
				if(y[l]==t[i][k])k++;
				if(k==t[i].size()){
					k=kmp[k];
					Vis[l]=1;
				}
			};
			for(int j=R;j<min(L+s[i].size(),x.size());j++){
				if(Vis[j]&&vis[j])ans++;
			}
			for(int j=0;j<x.size();j++)Vis[j]=vis[j]=0;
		};
		printf("%d\n",ans);
	}
	return 0;
}
