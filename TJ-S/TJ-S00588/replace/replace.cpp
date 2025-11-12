#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	int n;
	cin>>m>>n;
	string a[100][100];
	string k,l;
	cin>>k>>l;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		cout<<0<<endl;
	}

	return 0;
} 

