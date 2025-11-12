#include<bits/stdc++.h>
using namespace std;

int n,q;
char s1[2010][2010],s2[2010][2010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		if(n<=2009)scanf("\n%s %s",s1[i],s2[i]);
		else getchar();
	}
	while(q>0){
		q--;
		char t1[2010],t2[2010];
		scanf("\n%s %s",t1,t2);
		int cy=0;
		int ans=0;
		int len1=strlen(t1),len2=strlen(t2);
		for(int l=0;l<len1;l++){
			if(t1[l]!=t2[l])cy++;
		}
		
		if(len1!=len2||n>2009){
			printf("0\n");
			continue;
		}
		for(int i=0;i<len1;i++){
			for(int cd=1;cd<=len1-i;cd++){//枚举长度
				
				
				for(int j=1;j<=n;j++){//可以与哪个换
					bool flag=1;
					int bq=0;
					
					if(cd==int(strlen(s1[j]))){
						for(int l=i;l<i+cd;l++){
							//printf("%c %c %c %c\n",t1[l],s1[j][l-i],t2[l],s2[j][l-i]);
							if(t1[l]!=s1[j][l-i]||t2[l]!=s2[j][l-i]){
								flag=0;
								break;
							}
							if(t1[l]!=t2[l])bq++;
						}
					}
					//printf("%d %d %d\n",flag,bq,cy);
					if(flag&&bq==cy)ans++;
				}
				
			}
		}
		printf("%d\n",ans);
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
teshuxingzhiA
*/