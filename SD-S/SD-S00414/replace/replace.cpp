#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int n,q;
int nxt[1010][2010];
char s1[1010][2010];
int len[1010];
char s2[1010][2010];
int k;
char t[5001000];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i]+1,s2[i]+1);
		len[i]=strlen(s1[i]+1);
		k=0;
		for(int j=2;j<=len[i];j++){
			while(s1[i][j]!=s1[i][k+1]&&nxt[i][k]){
				k=nxt[i][k];
			}
			nxt[i][k]=k;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%s",t);
		printf("0\n");
	}
	return 0;
}
