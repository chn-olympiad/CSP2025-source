#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[105][3][105];
char t1[105];
char t2[105];
char t3[105];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i][1]+1);
		scanf("%s",s[i][2]+1);
	}
	for(int i=1;i<=q;i++){
		scanf("%s",t1+1);
		scanf("%s",t2+1);
		int l1=strlen(t1+1),l2=strlen(t2+1);
		if(l1!=l2){
			printf("0\n");
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int ls=strlen(s[i][1]+1);
			for(int j=1;j+ls-1<=l1;j++){
				bool flag=1;
				for(int k=1;k<=ls;k++)
					if(s[i][1][k]!=t1[k+j-1]) flag=0;
				if(flag){
					for(int k=1;k<=l1;k++)
						t3[k]=t1[k];
					for(int k=1;k<=ls;k++)
						t3[k+j-1]=s[i][2][k];
					bool fflag=1;
					for(int k=1;k<=l1;k++)
						if(t3[k]!=t2[k]) fflag=0;
					if(fflag) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
