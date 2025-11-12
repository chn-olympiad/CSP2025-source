#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll T,n,sum=0;
bool flag[N];
int aa=0,bb=0,cc=0;
struct xin{
	ll a;
	ll b;
	ll c;
}a[N];
bool cmp1(xin a1,xin b1){return a1.a>b1.a;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			sum+=a[i].a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
// Ren5Jie4Di4Ling5%
 

