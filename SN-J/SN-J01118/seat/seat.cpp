#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int N=n*m;
	int a[105]; 
	for(int i=0;i<=N;i++){
		cin>>a[i];
		if(a[1]>a[i])cout<<1<<" "<<1;
	};
	return 0;
}
