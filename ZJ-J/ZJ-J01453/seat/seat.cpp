#include<bits/stdc++.h>
using namespace std;
struct info{
	int s,h,l;
}a[110];
int n,m;
bool cmp(info x,info y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].s;
	int k=a[1].s;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				int num=(i-1)*n+j;
				a[num].h=j;
				a[num].l=i;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				int num=(i-1)*n+(n-j+1);
				a[num].h=j;
				a[num].l=i;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].s==k){
			cout<<a[i].l<<" "<<a[i].h;
			return 0;
		}
	}
	return 0;
}