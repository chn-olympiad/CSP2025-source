#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+5,M=5e6+5;
const ull base=131;
int n,q,ans,ml,po1,po2,l[N],po[30][N],qy[30],cnt[30];
ull ha1,ha2,p[M],h1[N],h2[N],hs1[M],hs2[M];
char s1[M],s2[M];
bool cmp(int A,int B){
	return l[A]>l[B];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		l[i]=strlen(s1+1);
		ha1=ha2=0;
		for(int j=1;j<=l[i];j++){
			ha1=ha1*base+s1[j]-'a';
			ha2=ha2*base+s2[j]-'a';
		}
		h1[i]=ha1; h2[i]=ha2;
		po[s1[1]-'a'][++cnt[s1[1]-'a']]=i;
		ml=max(ml,l[i]);
	}
	for(int i=0;i<=25;i++)
		if(cnt[i]!=0) sort(po[i]+1,po[i]+1+cnt[i],cmp);
	p[0]=1;
	for(int i=1;i<=ml;i++) p[i]=p[i-1]*base;
	for(int i=1;i<=q;i++){
		ans=0;
		for(int i=0;i<=25;i++) qy[i]=1;
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int le1=strlen(s1+1);
		int le2=strlen(s2+1);
		if(le1!=le2){
			printf("0\n"); continue;
		}
		for(int j=1;j<=le1;j++){
			hs1[j]=hs1[j-1]*base+s1[j]-'a';
			hs2[j]=hs2[j-1]*base+s2[j]-'a';
		}
		for(int j=1;j<=le1;j++)
			if(s1[j]!=s2[j]){
				po1=j; break;
			}
		for(int j=le1;j>=1;j--)
			if(s1[j]!=s2[j]){
				po2=j; break;
			}
		for(int j=1;j<=po1;j++){
			while(j+l[po[s1[j]-'a'][qy[s1[j]-'a']]]-1>le1) qy[s1[j]-'a']++;
			for(int y=qy[s1[j]-'a'];y<=cnt[s1[j]-'a'];y++){
				int x=po[s1[j]-'a'][y];
				if(j+l[x]<=po2||j+l[x]-1>le1) break;
				if(hs1[j+l[x]-1]-hs1[j-1]*p[l[x]]==h1[x])
					if(hs2[j+l[x]-1]-hs2[j-1]*p[l[x]]==h2[x])
						ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}