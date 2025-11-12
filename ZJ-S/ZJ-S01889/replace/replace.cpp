#include<bits/stdc++.h>
using namespace std;
const int MS=1000+5;
int n,q,len[MS];
char s[MS][5][2*MS],t1[2*MS],t2[2*MS];
bool check(int x,int pos){
	for(int i=pos;i<pos+len[x];i++)
		if(t1[i]!=s[x][1][i-pos]||t2[i]!=s[x][2][i-pos])
			return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=2000){
		for(int i=1;i<=n;i++){
			scanf("%s",s[i][0]);
			int j=0;
			while(s[i][0][j]!=' '){
				s[i][1][j]=s[i][0][j];
			}
			for(int k=0;k<j;k++)
				s[i][2][k]=s[i][0][j];	
			len[i]=j;
		}
		while(q--){
			scanf("%s",s[n+1][0]);
			int j=0;
			while(s[n+1][0][j]!=' '){
				t1[j]=s[n+1][0][j];
			}
			for(int k=0;k<j;k++)
				t2[k]=s[n+1][0][j];
			int ans=0;
			for(int i=1;i<=n;i++){
				int b=1;
				int k=0;
				while(k<j){
					if(t1[k]!=t2[k]){
						if(check(i,k)){
							k=k+len[i];
						}else{
							b=0;break;
						}
					}else k++;
				}
				ans+=b;
			}
		printf("%d\n",ans);		
		}
	}
	else{
		for(int i=1;i<=q;i++)
			printf("0\n");
	}
	return 0;
}
