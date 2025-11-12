#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,k,ans,a[N],cnt;
struct qu{
	int l,r,num;
}q[2*N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n >>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int sum=0,l=i,r=j;
			for(int o=l;o<=r;++o){
				sum^=a[o];
			}
			if(sum==k) {
				q[++cnt].l=l;
				q[cnt].r=r;
				q[cnt].num=r-l+1;	
			}
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=i+1;j<=cnt;++j){
			if((q[i].l>=q[j].l&&q[i].l<=q[j].r)||(q[i].r>=q[j].l&&q[i].r<=q[j].r)||
				(q[j].l>=q[i].l&&q[j].l<=q[i].r)||(q[j].r>=q[i].l&&q[j].r<=q[i].r)){
				if(q[i].num>=q[j].num){
					q[i].l=q[i].r=q[i].num=0;
				}
				else{
					q[j].l=q[j].r=q[j].num=0;
				}
			}
		}
	}
	for(int i=1;i<=cnt;++i){
		if(q[i].l!=0&&q[i].r!=0&&q[i].num!=0) ans++;
	}
	cout<<ans;
	return 0;
}
