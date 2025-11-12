#include<bits/stdc++.h>
using namespace std;
struct p{
	int v;
}a[114];
bool cmp(p x,p y){
	return x.v>y.v;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i].v;
	int r=a[0].v,ans=0;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].v==r) ans=i+1;
	}
	int k=(ans-1)/n+1;
	int h=ans-(k-1)*n;
	if(k%2==1){
		cout<<k<<" "<<h;
	}else{
		cout<<k<<" "<<n-h+1;
	}
	return 0;
}
