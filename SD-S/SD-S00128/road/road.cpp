#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=1e6+10;
ll n,m,p[N],sum=0,k;
struct poll{
	ll x,y,z;
}a[N];
ll cmp(poll a,poll b){
	return a.z<b.z;
}
ll find(ll a){
	if(p[a]!=a) p[a]=find(p[a]);
	return a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) p[i]=i;
	for(ll i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
	} 
	sort(a+1,a+1+m,cmp);
	for(ll i=1;i<=m;i++){
		ll xx=find(a[i].x),yy=find(a[i].y);
//		cout<<p[xx]<<" "<<yy<<endl;
		if(p[xx]!=yy){
//			cout<<p[xx]<<" "<<yy<<endl;
//			p[xx]=p[yy];
			p[xx]=yy; 
//			cout<<p[xx]<<" "<<yy<<endl;
			sum+=a[i].z;
		}
//		cout<<endl;
	}
	cout<<sum;
	return 0;
}
/*
5 6 0
1 2 1
1 2 6
2 3 2
3 4 6
3 4 1
4 5 3
*/
