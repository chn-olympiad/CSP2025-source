#include<bits/stdc++.h>
using namespace std;
long long n,k,ma=LLONG_MIN,mi=LLONG_MAX,ans,sum,a[500010],r[500010];
struct node{
	int l,r;
}b[500010];
bool cmp(node p,node q){
	if(p.r==q.r) return p.l<q.l;
	else return p.r<q.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]),mi=min(mi,a[i]);
	}
	if(ma==mi&&ma==k) printf("%lld",n),exit(0);
	if(ma==mi&&k==0) printf("%lld",n/2),exit(0);
	if(ma<=1&&k<=1){
		for(int i=1;i<=n;i++)
			if(a[i]==k) ans++;
			else if((a[i]^a[i+1])==k) ans++,i++;
		printf("%lld",ans),exit(0);
	}
	for(int i=1;i<=n;i++){
		b[i].l=i;
		sum=a[i];
		if(sum==k) b[i].r=i;
		for(int j=i+1;j<=n;j++){
			if((sum^a[j])==k||b[i].r!=0){
				b[i].r=j;
				break;
			}
		}
		if(b[i].r==0) b[i].r=1e9;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[j].r==1e9) break;
			if(b[i].r<b[j].l){
				ans++,i=j;
				break;	
			}
		}
	}
	cout<<ans;
	return 0;
}