#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m,k=0,a[110],x[110],y[110];
	bool p=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[k++];
		}
	}
	int o=a[0];
	sort(a,a+k,cmp);
	x[0]=1;
	for(int i=1;i<=100;i++){
		x[i]=x[i-1];
		if(p){
			x[i]++;
		}
		else{
			x[i]--;
		}
		if(x[i]>m){
			x[i]=m;
			p=0;
		}
		if(x[i]<1){
			x[i]=1;
			p=1;
		}
	}
	y[0]=1;
	for(int i=1;i<=100;i++){
		y[i]=i/m+1;
	}
	for(int i=0;i<k;i++){
		if(a[i]==o){
			cout<<y[i]<<" "<<x[i];
			break;
		}
	}
	return 0;
}

