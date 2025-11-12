#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[500005],l,l2;
struct node{
	int l,r;

}b[500005],c[500005];
bool cmp(node x,node y){
	return x.l<y.l;
}
bool cmp2(node x,node y){
	if(x.r!=y.r){
		return x.r>y.r;
	}else{
		return x.l<y.l;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		ll r=a[i];
		if(a[i]==k){
			b[++l2].l=i;
			b[l2].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			r^=a[j];
			if(r==k){
				b[++l2].l=i;
				b[l2].r=j;
				break;
			}
		}
	}
	
	sort(b+1,b+l2+1,cmp2);
	/*for(int i=1;i<=l2;i++){
		printf("%d %d",b[i].l,b[i].r);
	}*/
	for(int i=1;i<=l2;i++){
		int j=i+1;
		bool ok=1;
		while(ok&&j<=n){
			if(b[j].l>=b[i].l&&b[j].r<=b[i].r){
				ok=0;
				break;
			}
			++j;
		}
		if(ok){
			c[++l].l=b[i].l;
			c[l].r=b[i].r;
		}
	}
	int nr=0,ans=0;
	sort(c+1,c+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(i==1){
			++ans;
			nr=c[i].r;
			//printf("%d %d\n",c[i].l,c[i].r);
		}else{
			if(c[i].l>nr){
				++ans;
				nr=c[i].r;
				//printf("%d %d\n",c[i].l,c[i].r);
			}
		}
	}
	printf("%d",ans);
    return 0;
}

