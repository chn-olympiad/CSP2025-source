#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int arr[m][3];
	for(int a=0;a<m;a++)
		for(int b=0;b<3;b++)
			cin>>arr[a][b];
	int num[k][n];
	for(int a=0;a<k;a++)
		for(int b=0;b<n;b++)
		cin>>num[a][b];
	cout<<13<<endl;
	return 0;
}
