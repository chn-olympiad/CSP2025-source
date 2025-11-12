#include<bits/stdc++.h>
#define maxn 5000005
using namespace std; 
long long n,k,a[maxn],fsum[maxn],ans,_p;
struct jjq{
	long long l,r,f=0;
}p[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		fsum[i]=fsum[i-1]^a[i];
	//	printf("%d ",fsum[i]);
	}
	//cout<<endl;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if ((fsum[i]^fsum[j])==k){
			//	printf("%d %d\n",i+1,j);
				ans++;
			//	p[_p].nxt=_p;
				p[++_p].l=i+1;
				p[_p].r=j;
			}
		}
	}
	for (int i=1;i<_p;i++){
		for (int j=i+1;j<=_p;j++){
			if (p[i].f||p[i].r<p[j].l)break;
			if (p[j].f)continue;
			if (p[i].r>=p[j].l){
				ans--;
				if (p[i].r>=p[j].r){
					p[i].f=1;
				//	printf("%d %d\n",p[i].l,p[i].r);
				}
				else {
					p[j].f=1;
					//printf("%d %d\n",p[j].l,p[j].r);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 3
2 1 0 3
*/
