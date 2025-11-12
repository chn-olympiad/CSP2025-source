#include<bits/stdc++.h>
#define ll long long

using namespace std;
bool cmp(ll x,ll y){
	return x>y;
}
ll x,y,n,r,p;
ll a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&x,&y);
	n=x*y;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	printf("%lld ",(p/x+p%x%2));
	ll h;
	if(p%(y*2)==0){
		h=1;
	}
	else if(p%(y*2)>y){
		h=y-(p%(y*2)-y)+1;
	}else{
		h=p%(y*2);
	}
	printf("%lld",h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
