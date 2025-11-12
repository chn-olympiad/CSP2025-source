#include <bits/stdc++.h>
using namespace std;
int n,m;
struct point{
	int tot,id;
}a[110];
bool cmp(point x,point y){
	return x.tot>y.tot;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].tot;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=m;i+=2){
		for (int j=1;j<=n;j++){
			if (a[j+(i-1)*n].id==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		int k=1;
		for (int j=n;j>=1;j--){
			if (a[k+i*n].id==1){
				cout<<i+1<<" "<<j;
				return 0;
			}
			k++;
		}
	}
	if (m%2==1){
		for (int i=1;i<=n;i++){
			if (a[i].id==1){
				cout<<i<<" "<<m;
			}
		}
	}
	return 0;
}
