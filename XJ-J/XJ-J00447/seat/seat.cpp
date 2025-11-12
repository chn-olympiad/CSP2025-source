#include <bits/stdc++.h>
using namespace std;
double a[1005];
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	double n,m;
	long long cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	//cout<<cnt<<" ";
	double h=ceil(cnt/n);
	double l=int(cnt)%int(n);
	cout<<h;
	cout<<" ";
	//'cout<<l<<" ";
	if(l==0){
		cout<<n;
		return 0;
	}
	if(int(h)%2!=0){
		cout<<l;
	}else{
		cout<<n-l+1;
	}
	return 0;
}
