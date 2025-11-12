#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e6+6,M=2e5+5,P=998244353;
void write(int x){
	if(x==0){putchar('0');return;}
	int l=0;char c[8];
	while(x)c[++l]=x%10+48,x/=10;
	while(l)putchar(c[l]),l--;
}
int n,q,l[M];
char a[N],c[N];
ull hs[M],hs1[M],p[N];
unordered_map<ull,vector<int> >mp;
vector<int>g[M];
ull ha[N];
inline int G(int x,int j,int m){
	int y=x+l[j]-1;
	if(hs[j]==ha[y]-ha[x-1]*p[l[j]])return 1;
	return 0;
}
inline ull Q(int x,int j,int m){
	return (hs1[j]-hs[j])*p[m-x-l[j]+1];
}
void work(){
	scanf("%s%s",a+1,c+1);
	int m=strlen(a+1),x,y,s=0;x=0;
	ull h,hc;h=hc=0;
	if(strlen(c+1)!=m)return printf("0\n"),void();
	for (int i=1;i<=m;i++)
		if(a[i]!=c[i])x=(x?x:i),y=i;
	for (int i=x+1;i<=y;i++)h=h*P+a[i];
	for (int i=1;i<=m;i++)
		ha[i]=ha[i-1]*P+a[i],hc=hc*P+c[i];
	for (int i=x;i;i--){
		h+=p[y-i]*a[i];
		if(!mp[h].size())continue;
		for (int j:mp[h]){
			if(G(i,j,m)&&ha[m]+Q(i,j,m)==hc)s++;
		}
	}
	write(s),putchar('\n');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);p[0]=1;
	for (int i=1;i<N;i++)p[i]=P*p[i-1];
	for (int i=1;i<=n;i++){
		scanf("%s%s",a+1,c+1);
		l[i]=strlen(a+1);
		for (int j=1;j<=l[i];j++)
			hs[i]=hs[i]*P+a[j],mp[hs[i]].push_back(i);
		for (int j=1;j<=l[i];j++)hs1[i]=hs1[i]*P+c[j];
	}
	while(q--)work();
}
