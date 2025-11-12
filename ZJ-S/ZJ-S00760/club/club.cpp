#include<bits/stdc++.h>
using namespace std;
int T,n,ma,i,fl;
struct no{int x,y,z;}a[100010];
bool cmp(no a,no b){
	return a.x>b.x;
}
void dfs(int t,int x,int y,int z,int s){
	if(t>n){
		ma=max(ma,s);return;
	}
	if(x<n/2)dfs(t+1,x+1,y,z,s+a[t].x);
	if(y<n/2)dfs(t+1,x,y+1,z,s+a[t].y);
	if(z<n/2)dfs(t+1,x,y,z+1,s+a[t].z);
}
void work1(){
	int i,s=0;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n/2;i++)s+=a[i].x;
	printf("%d\n",s);
}
void dfs2(int t,int x,int y,int s){
	if(t>n){
		ma=max(ma,s);return;
	}
	if(x<n/2)dfs2(t+1,x+1,y,s+a[t].x);
	if(y<n/2)dfs2(t+1,x,y+1,s+a[t].y);
}
void work2(){
	int ma=0;dfs2(1,0,0,0);printf("%d\n",ma);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(fl==1)work1();
		else if(fl==2)work2();
		else if(fl==-1)ma=0,dfs(1,0,0,0,0),printf("%d\n",ma);
		else{
			fl=1;
			for(i=1;i<=n;i++)
				if(a[i].y||a[i].z)fl=-1;
			if(fl==1)work1();
			else{
				fl=2;
				for(i=1;i<=n;i++)
					if(a[i].z)fl=-1;
				if(fl==2)work2();
				else{
					ma=0;
					dfs(1,0,0,0,0);
					printf("%d\n",ma);
				}
			}
		}
	}
	return 0;
}
