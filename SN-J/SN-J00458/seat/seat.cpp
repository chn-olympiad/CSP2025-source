//SN-J00458 戴思诚 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],r,d;
int main(){
	int d2=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	r=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>r){
				d++;
			}
		}
	}
	if(d>=n){
		while(1){
			d2++;
			d-=n;
			if(d<n){
				break;
			}
		}
		if(d==0){
			d++;
		}
		if(d2%2==1){
			cout<<d2<<" "<<d;
		}
		else{
			cout<<d2<<" "<<m-d+1;
		}
		return 0;
	}
	else{
		cout<<1<<" "<<d+1;
		return 0;
	}
	return 0;
}
