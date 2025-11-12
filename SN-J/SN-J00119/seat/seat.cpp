#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int b[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	int d=n*m;
	int N=1,M=1;
	int a[105];
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(1,1+d+a,cmp);
	int x=1,y=n,z=1;
	for(int i=1,i<=m;i++){
		for(int j=x;j<=y;j+=z){
			b[i][j]=a[i]
			if(b[i][j]==o){
				cout<<b[i][j];
				return 0;
			}
			if(j==n){
				x=n;
				y=1;
				z=-1;
			}
			else if(j==1){
				x=1;
				y=n;
				z=1;
			}
		}
	}
	return 0;
}
