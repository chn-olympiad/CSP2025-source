#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[200005];
bool cmp(node a,node b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
int n,m,top1,top2,f[200005];
char c1[200005],c2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	char c=' ';
	for(int i=1;i<=n;i++){
		top1=top2=0;
		while(!(c>='a'&&c<='z')) c=getchar();
		while(c>='a'&&c<='z') c1[++top1]=c,c=getchar();
		while(!(c>='a'&&c<='z')) c=getchar();
		while(c>='a'&&c<='z') c2[++top2]=c,c=getchar();
		int k1=0,k2=0;
		for(int j=1;j<=top1;j++) if(c1[j]=='b'){ k1=j;break; }
		for(int j=1;j<=top1;j++) if(c2[j]=='b'){ k2=j;break; }
		a[i]={k1,k2-k1};
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		top1=top2=0;
		while(!(c>='a'&&c<='z')) c=getchar();
		while(c>='a'&&c<='z') c1[++top1]=c,c=getchar();
		while(!(c>='a'&&c<='z')) c=getchar();
		while(c>='a'&&c<='z') c2[++top2]=c,c=getchar();
		int kk1=0,kk2=0;
		for(int j=1;j<=top1;j++) if(c1[j]=='b'){ kk1=j;break; }
		for(int j=1;j<=top1;j++) if(c2[j]=='b'){ kk2=j;break; }
		int l=1,r=n,mid,k1=0,k2;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid].y>=kk2-kk1) r=mid-1,k1=mid;
			else l=mid+1;
		}
		if(a[k1].y!=kk2-kk1){ printf("0\n");continue; }
		l=k1,r=n,mid,k2=l-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid].y==kk2-kk1&&a[mid].x<=kk1) l=mid+1,k2=mid;
			else r=mid-1;
		}
		printf("%d\n",k2-k1+1);
	}
	return 0;
} 
