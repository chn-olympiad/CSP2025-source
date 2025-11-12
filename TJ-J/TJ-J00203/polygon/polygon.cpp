#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int r[n]={0};
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	int m;
	m=r[n-1]+r[n-2];
	cout<<m;
}
