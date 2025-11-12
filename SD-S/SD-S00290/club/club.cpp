#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+20;
ll t;
struct nod{
	ll num,id;
};
struct node{
	nod b[4];
}a[N];
bool cm(nod x,nod y){
	return x.num>y.num;
}
bool cmp(node c,node d){
	if(c.b[1].id!=d.b[1].id){
		return c.b[1].id<d.b[1].id;
	}
	if(c.b[1].num-c.b[2].num!=d.b[1].num-d.b[2].num){
		return c.b[1].num-c.b[2].num>d.b[1].num-d.b[2].num;
	}
	if(c.b[2].id!=d.b[2].id){
		return c.b[2].id<d.b[2].id;
	}
	if(c.b[2].num-c.b[3].num!=d.b[2].num-d.b[3].num){
		return c.b[2].num-c.b[3].num>d.b[2].num-d.b[3].num;
	}
	return c.b[3].id<d.b[3].id;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].b[1].num>>a[i].b[2].num>>a[i].b[3].num;
			a[i].b[1].id=1,a[i].b[2].id=2,a[i].b[3].id=3;
			if(a[i].b[2].num<a[i].b[3].num){
				swap(a[i].b[2].num,a[i].b[3].num);
				swap(a[i].b[2].id,a[i].b[3].id);
			}
			if(a[i].b[1].num<a[i].b[2].num){
				swap(a[i].b[2].num,a[i].b[1].num);
				swap(a[i].b[2].id,a[i].b[1].id);
			}
			if(a[i].b[2].num<a[i].b[3].num){
				swap(a[i].b[2].num,a[i].b[3].num);
				swap(a[i].b[2].id,a[i].b[3].id);
			}
		}
		sort(a+1,a+1+n,cmp);
		ll v[4];
		ll ans=0;
		v[1]=v[2]=v[3]=0;
		for(ll i=1;i<=n;i++){
			if(v[a[i].b[1].id]>=n/2){
				if(v[a[i].b[2].id]+1<=n/2){
					v[a[i].b[2].id]++;
					ans+=a[i].b[2].num;
				}
				else{
					v[a[i].b[3].id]++;
					ans+=a[i].b[3].num;
				}
			}
			else{
				v[a[i].b[1].id]++;
				ans+=a[i].b[1].num;
			}
		}
		cout<<ans<<"\n";
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				a[i].b[j].id=a[i].b[j].num=0;
			}
		}
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
