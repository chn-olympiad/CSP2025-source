#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,a[10000],cj,pm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	cj=a[0];
	//cout<<cj<<endl; 
	sort(a,a+(n*m));
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==cj){
			pm=n*m-i;
			break;
		}
	}
	//cout<<pm<<endl;
	x=(pm+n-1)/n;
	if(x%2){
		y=pm-(x-1)*n;
	}
	else{
		y=n-(pm-(x-1)*n)+1;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
