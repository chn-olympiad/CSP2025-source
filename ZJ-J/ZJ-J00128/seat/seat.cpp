#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num,pi;
}a[401];
bool cmp(node x,node y){
	return x.num>y.num;
}
long long n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].pi=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i].pi==1){
			long long ansx=(i-1)/n+1,ansy=(i-(ansx-1)*n);
			if(ansx%2==0){
				ansy=n-ansy+1;
			}
			cout<<ansx<<' '<<ansy;
			return 0;
		}
	}
	return 0;
}
