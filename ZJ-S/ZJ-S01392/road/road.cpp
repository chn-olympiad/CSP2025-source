#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,i,f[20000],b[20][20000],j,s,x,y,op;
void read(int &x){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	x=0;
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
}
struct node{int x,y,z;}a[2000000];
bool cmp(const node&x,const node&y){return x.z<y.z;}
int find(int x){
	return (f[x]==x)?x:(f[x]=find(f[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++){
		read(a[i].x);read(a[i].y);read(a[i].z);
	}
	for(i=1;i<=k;i++){
		read(b[i][0]);
		op=-1;
		for(j=1;j<=n;j++){
			read(b[i][j]);
			if(b[i][0]==0&&b[i][j]==0){
				if(op==-1)op=find(j);
				else{
					f[j]=op;
				}
			}	
		}
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++){
		x=find(a[i].x);y=find(a[i].y);
		if(x!=y)s+=a[i].z,f[x]=y;
	}
	printf("%lld",s);
	return 0;
}
