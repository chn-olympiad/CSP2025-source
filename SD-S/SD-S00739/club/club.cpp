#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace StarRail{
	struct r{
		ll a,b,c,val;
	}a[100005];
	int aa[100005],ab[100005],ac[100005];
	bool cmp(int x,int y){
		return a[x].val>a[y].val;
	}
	void main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		//freopen("club5.in","r",stdin);
		//freopen("club5.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int T,Cyrene=6+5;
		cin>>T;
		while(T--){
			int n;
			ll ans=0;
			cin>>n;
			int ca=0,cb=0,cc=0;
			for(int i=1;i<=n;i++){
				cin>>a[i].a>>a[i].b>>a[i].c;
				if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
					aa[++ca]=i;
					a[i].val=a[i].a-max(a[i].b,a[i].c);
				}
				else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
					ab[++cb]=i;
					a[i].val=a[i].b-max(a[i].a,a[i].c);
				}
				else{
					ac[++cc]=i;
					a[i].val=a[i].c-max(a[i].a,a[i].b);
				}
			}
			sort(aa+1,aa+ca+1,cmp);
			sort(ab+1,ab+cb+1,cmp);
			sort(ac+1,ac+cc+1,cmp);
			for(int i=1;i<=ca;i++){
				if(i<=n/2)ans+=a[aa[i]].a;
				else ans+=max(a[aa[i]].b,a[aa[i]].c);
			}
			for(int i=1;i<=cb;i++){
				if(i<=n/2)ans+=a[ab[i]].b;
				else ans+=max(a[ab[i]].a,a[ab[i]].c);
			}
			for(int i=1;i<=cc;i++){
				if(i<=n/2)ans+=a[ac[i]].c;
				else ans+=max(a[ac[i]].a,a[ac[i]].b);
			}
			cout<<ans<<'\n';
		}
	}
}
int main(){
	StarRail::main();
}
