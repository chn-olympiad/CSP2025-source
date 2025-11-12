#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
struct node{
	int v,q,w,e,qi,wi,ei;
}a[200100];
bool cmp(node x,node y){
	if(x.q==y.q){
		if(x.w==y.w)return x.e>y.e;
		return x.w>y.w;
	}
	return x.q>y.q;
}
int nn[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int s=0;
		memset(nn,0,sizeof(nn));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].q,&a[i].w,&a[i].e);
			a[i].qi=1,a[i].wi=2,a[i].ei=3;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				if(a[i].q<a[i].w){
					swap(a[i].q,a[i].w);
					swap(a[i].qi,a[i].wi);
				}
				if(a[i].w<a[i].e){
					swap(a[i].w,a[i].e);
					swap(a[i].wi,a[i].ei);
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(nn[a[i].qi]==n/2){
				if(nn[a[i].wi]==n/2){
					s+=a[i].e;
					nn[a[i].ei]++;
				}
				else{
					s+=a[i].w;
					nn[a[i].wi]++;
				}
			}
			else{
				s+=a[i].q;
				nn[a[i].qi]++;
			}
//			cout<<s<<endl;
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].q<<' '<<a[i].w<<' '<<a[i].e<<endl;
//		}
		printf("%d\n",s);
	}
	return 0;
}
