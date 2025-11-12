#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int P=131;
int n,q;
unsigned long long pre[N][2],sum[2],num[2];
string s[N][2],t[2];
ll ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++) pre[i][0]=pre[i][0]*P+s[i][0][j];
		for(int j=0;j<s[i][1].size();j++) pre[i][1]=pre[i][1]*P+s[i][1][j];
	}
	for(int i=1;i<=q;i++) {
		ans=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			puts("0");
			continue;
		}
		int st=0,en=0;
		for(int j=0;j<t[0].size();j++)
			if(t[0][j]!=t[1][j]){
				if(!st) st=j;
				en=j;
			} 
		for(int j=st;j<=en;j++){
			num[0]=num[0]*P+t[0][j];
			num[1]=num[1]*P+t[1][j];
		}
		sum[0]=sum[1]=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<s[j][0].size();k++){
				if(pre[j][0]-sum[0]==num[0]&&
					pre[j][1]-sum[1]==num[1]) ans++;
				sum[0]=sum[0]*P+s[j][0][k];
				sum[1]=sum[1]*P+s[j][1][k];
				if(s[j][0][k]!=s[j][1][k]) break;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}

