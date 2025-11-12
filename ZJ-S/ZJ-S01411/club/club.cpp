#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll t,n,js[5];
struct node{
	ll num,id,di;
};
node x[N];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		js[1]=js[2]=js[3]=0;
		ll ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			ll a,b,c,flag;
			cin >> a >> b >> c;
			if(a>=b&&a>=c){
				flag=1;
				ans+=a;
			} else if(b>=c){
				flag=2;
				ans+=b;
			} else {
				flag=3;
				ans+=c;
			}
			x[i].id=flag;
			if(flag==1){
				x[i].num=min(a-b,a-c);
				if(b>=c){
					x[i].di=2;
				} else {
					x[i].di=3;
				}
			} else if(flag==2){
				x[i].num=min(b-a,b-c);
				if(a>=c){
					x[i].di=1;
				} else {
					x[i].di=3;
				}
			} else{
				x[i].num=min(c-a,c-b);
				if(a>=b){
					x[i].di=1;
				} else {
					x[i].di=2;
				}
			}
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(js[x[i].id]>=n/2){
				ans-=x[i].num;
				js[x[i].di]++;
			} else {
				js[x[i].id]++;
			}
		}
		cout << ans <<"\n";
	}
	return 0;
} 
