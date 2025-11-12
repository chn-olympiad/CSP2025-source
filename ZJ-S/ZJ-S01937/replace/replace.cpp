#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[5000002];
int l[200002],xa[200002],xb[200002];
char s1[102][202],s2[102][202];
bool check(char s1[],char s2[]){
	int l=strlen(s1);
	for(int i=0;i<l;i++){
		if(s1[i]!=s2[i]){
			return 0;
		}
	}
	return 1;
}
bool check_(char s1[],char s2[],int L,int R){
	for(int i=L;i<=R;i++){
		if(s1[i]!=s2[i-L]){
			return 0;
		}
	}
	return 1;
}
void cha(char s1[],char s2[],int L,int R){
	for(int i=L;i<=R;i++){
		s1[i]=s1[i-L];
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
//	if(n<=100){
//		for(int i=1;i<=n;i++){
//			scanf("%s%s",s1[i],s2[i]);
//			l[i]=strlen(s1[i]);
//		}
//		while(q--){
//			int ans=0;
//			char t1[202],t2[202],t_[202];
//			scanf("%s%s",t1,t2);
//			int len=strlen(s1),len_=strlen(s2);
//			if(len!=len_){
//				puts("0");
//				continue;
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=0;j+l[i]<=len;j++){
//					if(check_(t1,s1[i],j,j+l[i]-1)){
//						for(int i=0;i<len;i++){
//							t_[i]=t1[i];
//						}
//						cha(t_,t1,j,j+l[i]-1);
//						if(check(t_,t2)){
//							++ans;
//							break;
//						}
//					}
//				}
//			}
//			printf("%d\n",ans);
//		}
//	}
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		l[i]=strlen(s);
		for(int j=0;j<l[i];j++){
			if(s[j]=='b'){
				xa[i]=j;
			}
		}
		scanf("%s",s);
		for(int j=0;j<l[i];j++){
			if(s[j]=='b'){
				xb[i]=j;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",l[i],xa[i],xb[i]);
//	}
	while(q--){
		int ya,yb,ans=0;
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='b'){
				ya=i;
			}
		}
		scanf("%s",s);
		int len_=strlen(s);
		for(int i=0;i<len_;i++){
			if(s[i]=='b'){
				yb=i;
			}
		}
		if(len!=len_){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++){
			if((ya-yb)==(xa[i]-xb[i])&&ya>=xa[i]&&(len-yb)>=(l[i]-xb[i])){
//				printf("%d ",i);
				++ans;
			}
		}
//		puts("");
		printf("%d\n",ans);
	}
	return 0;
}
/*
5 5
ab ba
ab ab
aaaabaa aaaaaba
aab baa
aaaaabaa aaaaaaba
*/