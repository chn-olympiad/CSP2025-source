/*
#include<bits/stdc+.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

int a[100100][3],n,t,ans;
int mmax(int a,int b,int c){
	return (a>b && a>c) ? 0 : (b>c ? 1 : 2);
}
int mmid(int a,int b,int c){
	return (a>b && a>c) ? (b>c ? 1 : 2) : ((a>b || a>c) ? 0 : (b>c ? 2 : 1 ));
}
int mmin(int a,int b,int c){
	return (a<b && a<c) ? 0 : (b<c ? 1 : 2);
}
struct nod{
	int mi,plc;
	friend bool operator < (nod a,nod b){
		return a.mi>b.mi;
	}
};
priority_queue<nod>d[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		nod cur;
		for(int j=0;j<n;j++){
			scanf("%d%d%d",&a[j][0],&a[j][1],&a[j][2]);
			ans+=a[j][mmax(a[j][0],a[j][1],a[j][2])];
			cur.plc=j;
			cur.mi=a[j][mmax(a[j][0],a[j][1],a[j][2])]-a[j][mmid(a[j][0],a[j][1],a[j][2])];
			d[mmax(a[j][0],a[j][1],a[j][2])].push(cur);
		}for (int j=0;j<3;j++){
			while (d[j].size()>(n/2)){
				cur=d[j].top();
				d[j].pop();
				ans-=cur.mi;
			}while (d[j].size()>0){
				d[j].pop();
			}
		}printf("%d\n",ans);
	}
	
	return 0;
}
