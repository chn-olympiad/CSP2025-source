#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10,L=5e6+10;
int n,q;
int cnt[L<<1];
char s1[L],s2[L],t1[L],t2[L];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int flag00=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s1);
		int flag=0,pl1=0,pl2=0;
		for(int i=0;i<strlen(s1);i++){
			if(s1[i]=='b'&&!pl1) pl1=i;
			else if(s1[i]!='a') flag=1;
		}
		scanf("%s",s2);
		for(int i=0;i<strlen(s2);i++){
			if(s2[i]=='b'&&!pl2) pl2=i;
			else if(s2[i]!='a') flag=1;
		}
		cnt[pl1-pl2+L-10]++;
	}
	for(int i=1;i<=q;i++){
		scanf("%s",t1);
		int flag=0,pl1=0,pl2=0;
		for(int i=0;i<strlen(t1);i++){
			if(t1[i]=='b'&&!pl1) pl1=i;
			else if(t1[i]!='a') flag=1;
		}
		scanf("%s",t2);
		for(int i=0;i<strlen(t2);i++){
			if(t2[i]=='b'&&!pl2) pl2=i;
			else if(t2[i]!='a') flag=1;
		}
		printf("%d\n",cnt[pl1-pl2+L-10]);
	}
	return 0;
}
