#include<stdio.h>
#include<algorithm>
#include<string.h>
#define CSP_IO freopen("number.in","r",stdin);freopen("number.out","w",stdout);
using namespace std;
int vis[20];
char S[1000010];
signed main(){
	CSP_IO;
	scanf("%s",&S[1]);
	int n=strlen(&S[1]);
	for(int i=1;i<=n;i++){
		if(S[i]>='0'&&S[i]<='9')
			vis[S[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(vis[i]--)putchar(i+'0');
	}
	return 0;
}

