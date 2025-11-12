#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	z=b[0];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==z){
			y=i;
			break;
		}
		else{
			continue;
		}
	}
	if(y<=m){
		cout<<"1 "<<y;
		return 0;
	}
	int k=y/m;
	if(k%2==0){
		y=y-n*k;
		cout<<k<<" "<<y;
		return 0;
	}
	if(k%2!=0){
		y=y-n*k;
		y=m-y;
		cout<<k<<" "<<y;
		return 0;
	}
}
