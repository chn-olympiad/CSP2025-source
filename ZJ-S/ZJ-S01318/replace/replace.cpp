#include<bits/stdc++.h>
using namespace std;
int n,q,ans,p;char c[10005][4][1005],t[4][1005];bool v[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",&c[i][1],&c[i][2]);
	}
	while(q--){
		scanf("%s%s",&t[1],&t[2]);ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<strlen(t[1]);j++){
				if(c[i][1][0]==t[1][j]&&c[i][2][0]==t[2][j]){
					p=0;
					while(c[i][1][p+1]==t[1][j+p+1]&&c[i][2][p+1]==t[2][j+p+1]&&p<strlen(c[i][1])-1){p++;}
					if(p==strlen(c[i][1])-1){ans++;break;}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}