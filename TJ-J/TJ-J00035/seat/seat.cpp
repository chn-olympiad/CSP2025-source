#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,d;
	cin>>m>>n;
	int a[n*m];
	memset(a,0,sizeof(a));
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	d=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(d==a[i]){
			d=i;
			break;
		}
	}
	if((d/n+1)%2==0){
		cout<<d%m+1<<' ';
	}
	else{
		cout<<m-((d+1)%m)<<' ';
	}
	cout<<d/n+1;
	return 0;
}
