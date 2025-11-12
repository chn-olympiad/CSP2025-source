#include <bits/stdc++.h>
using namespace std;
struct Node{
	int num,x;
};
int t,n,a[100001][4],g[100001],po[100001],h[4];
bool cmp(Node a,Node b){
	if (a.x>b.x)return 1;
	else if(a.x<b.x)return 0;
	else return g[a.num]<g[b.num];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		memset(g,0,sizeof(g));
		memset(po,0,sizeof(po));
		memset(h,0,sizeof(h));
		cin>>n;
		for (int i=1;i<=n;i++){
			int p=-1;
			for (int j=1;j<=3;j++){
				cin>>a[i][j];
				if (p<a[i][j]){
					po[i]=j;
				}
				p=max(p,a[i][j]);
			}
			g[i]=p;
			h[po[i]]++;
		}
		if (h[1]<=n/2&&h[2]<=n/2&&h[3]<=n/2){
			int s=0;
			for (int i=1;i<=n;i++){
				s+=g[i];
			}
			cout<<s<<endl;
		}else{
			int ps,l;
			for (int i=1;i<=3;i++){
				if (h[i]>n/2){
					ps=i;
					break;
				}
			}
			l=h[ps]-n/2;
			Node f[100001];
			for (int i=1;i<=n;i++){
				f[i].num=i;
				int b=-1;
				for (int j=1;j<=3;j++){
					if (j==ps)continue;
					b=max(b,a[i][j]);
				}
				f[i].x=b;
			}
			sort(f+1,f+n+1,cmp);
			int s=0;
			for (int i=1;i<=n;i++){
				s+=g[i];
			}
			for (int i=1;i<=l;i++){
				s-=g[f[i].num];
				s+=f[i].x;
			}
			cout<<s<<endl;
		}
	}
	return 0;
} 
