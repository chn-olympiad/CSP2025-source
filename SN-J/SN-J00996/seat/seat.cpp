#include<bits/stdc++.h>
using namespace std;
struct hjh{
	int cj;
	int bh;
	int b,c;
}a[105];
bool cmp(hjh x,hjh y){
	return x.cj<y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;cin>>n>>m;
	double n_1=n-1;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i].cj;
		a[i].bh=i;
	}
	sort(a+1,a+1+nm,cmp);
	for(int i=nm;i>=1;i--){
		if(((nm-i)/n)%2==0){
			a[i].c=((nm-i)%n)+1;
			a[i].b=(nm-i)/n+1;
		}
		else if(((nm-i)/n)%2==1){
			a[i].c=n_1-(nm-i)%n;
			a[i].b=((nm-i)/n)%2+1;
		}
		if(a[i].bh==1){
			cout<<a[i].b<<" "<<a[i].c;
			return 0;
		}
	}
	return 0;
}
