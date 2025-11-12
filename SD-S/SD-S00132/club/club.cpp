#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10,M=1e5+10;

int n,m;
int f[N][5];
int a[N],b[N],c[N];
struct edge{
	int a,b,c;
	int maxx;
}e[N];
struct node{
	int a,b,c;
}k[N][5];
int Maxx(int a,int b,int c){
	if(a>b&&a>c)return 1;
	if(b>a&&b>c)return 2;
	if(c>a&&c>b)return 3;
}
bool cmp(edge a,edge b){
	return a.maxx<b.maxx;
}
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		bool flg=0;
		ans=0;
		memset(f,0,sizeof f);
		memset(k,0,sizeof k);
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			e[i].maxx=max(max(e[i].a,e[i].b),e[i].c);
			if(e[i].c!=0)flg=1;
		}
		sort(e+1,e+1+n,cmp);
		if(!flg){
			int k1=0,k2=0;
			for(int i=1;i<=n;i++){
				int t=Maxx(e[i].a,e[i].b,e[i].c);
				if(k1==m)ans+=e[i].b,k2++;
				else if(k2==m)ans+=e[i].a,k1++;
				else if(k1<m&&k2<m){
					ans+=e[i].maxx;
					if(t==1)k1++;
					else k2++;
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			int t=Maxx(f[i-1][1],f[i-1][2],f[i-1][3]);
			if(k[i-1][1].a>=m){
				f[i][1]=max(f[i-1][2],f[i-1][3])+e[i].a;
				if(f[i-1][2]>f[i-1][3])t=2;
				else t=3;
			}
			else f[i][1]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+e[i].a;
			k[i][1]=k[i-1][t];
			k[i][1].a++;
			t=Maxx(f[i-1][1],f[i-1][2],f[i-1][3]);
			if(k[i-1][2].b>=m){
				f[i][2]=max(f[i-1][1],f[i-1][3])+e[i].b;
				if(f[i-1][1]>f[i-1][3])t=1;
				else t=3;
			}
			else f[i][2]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+e[i].b;
			k[i][2]=k[i-1][t];
			k[i][2].b++;
			t=Maxx(f[i-1][1],f[i-1][2],f[i-1][3]);
			if(k[i-1][3].c>=m){
				f[i][3]=max(f[i-1][1],f[i-1][2])+e[i].c;
				if(f[i-1][1]>f[i-1][2])t=1;
				else t=2;
			}
			else f[i][3]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+e[i].c;
			k[i][3]=k[i-1][t];
			k[i][3].c++;
		}
		ans=max(f[n][1],max(f[n][2],f[n][3]));
		printf("%d\n",ans);
	}
	return 0;
}
/*
int j=0;
for(int i=1;i<p.size();i++){
	while(j>0&&p[i]!=p[j])j=nxt[j-1];
	if(p[i]==p[j])j++;
	nxt[i]=j;
}
*/
