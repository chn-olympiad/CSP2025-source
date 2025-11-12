#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
//priority_queue<int,vector<int>,greater<int> > q;
int t,n,a[3][100005],v[100005],bx,cx,bh;
int DFS(int x,int g,int al,int bl){
	if(g==n/2){
//		cout<<x<<" "<<g<<" "<<al<<" "<<(bh-bl)<<"\n";
		return (bh-bl+a[1][x])+(al+a[0][x]*-1);
	}
	if(x>=n){
		return 0;
	}
	if(v[x]==0){
		int maxn=0;
		for(int i=x+1;i<=n;i++){
//			cout<<a[0][i]*-1<<" "<<a[1][i]<<"\n";
			maxn=max(maxn,DFS(i,g+1,al+a[0][i]*-1,bl+a[1][i]));
		}
		v[x]=maxn;
//		cout<<x<<" "<<maxn<<"\n";
		return maxn;
	}else{
		return v[x];
	}
}
int main(){
//	FI("club");
//	FO("club");
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		bh=0;
		bx=0;
		cx=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
			a[0][i]*=-1;
			bh+=a[1][i];
			bx=max(bx,a[1][i]);
			cx=max(cx,a[2][i]);
		}
//		cout<<"bh "<<bh<<" bx "<<bx<<" cx "<<cx<<"\n";
		if(n==2){
			cout<<max(max(a[0][1]*-1+a[1][2],a[2][1]+a[1][2]),a[2][1]+a[0][2]*-1);
		}else if(bx==0&&cx==0){
			sort(a[0]+1,a[0]+1+n);
			int h=0;
			for(int i=1;i<=n/2;i++){
				h+=a[0][i]*-1;
			}
			cout<<h<<"\n";
		}else if(cx==0){
			cout<<DFS(0,0,0,0);
			cout<<"\n";
//			for(int i=1;i<=n;i++){
//				cout<<v[i]<<" ";
//			}
		}else{
			cout<<114514;
		}
	}
	return 0;
}
