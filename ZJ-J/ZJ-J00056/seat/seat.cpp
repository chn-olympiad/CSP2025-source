#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=1e2+5;
ll n,m,naid;
struct pts{
	ll pt;
	ll id;
};
pts a[num];
bool cmp(pts a,pts b){
	return b.pt<a.pt;
}
void fd(ll step,ll x,ll y){
	if(step==naid){
		printf("%lld %lld",x,y);
		return;
	}
	if(x==1&&y==1){
		fd(step+1,1,2);
	}
	else if((x&1)&&(y==n)||(!(x&1))&&(y==1)){
		fd(step+1,x+1,y);
	}
	else if(x&1){
		fd(step+1,x,y+1);
	}
	else{
		fd(step+1,x,y-1);		
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n*m;++i){
		scanf("%lld",&a[i].pt);
		a[i].id=i;
	}
	sort(a,a+n*m,cmp);
	for(ll i=0;i<n*m;++i)
		if(a[i].id==0){
			naid=i+1;
			break;
		}
	fd(1,1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}