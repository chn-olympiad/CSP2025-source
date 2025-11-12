#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int key=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c,r;
	int i;
	for(i=1;i<=n*m;++i){
		if(a[i]==key) break;
	}
    if(i%m==0) c=i/m;
    else c=(int)i/m+1;
	r=i-(c-1)*n;
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
} 
