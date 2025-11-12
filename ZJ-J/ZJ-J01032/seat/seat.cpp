#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct node{
	int f,mingzi;
}a[1000];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].mingzi=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j].mingzi==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				if(a[(i-1)*n+n-j].mingzi==1){
					cout<<i<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
