#include<bits/stdc++.h>
using namespace std;
struct P{
	int i,x;
}a[200005];
bool cmp(P x,P y){
	return x.x>y.x;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}
	int cnt=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++cnt].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}