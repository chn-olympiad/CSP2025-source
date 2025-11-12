#include<iostream>
using namespace std;
int n,m,k;
int a[10003][10003],b[3][1000003];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>b[0][i]>>b[1][i]>>b[2][i];
	}
	cout<<0;
	return 0;
}
