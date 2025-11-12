#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[11][11]={};
	int b[11]={};
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	cout<<n<<","<<m;
	return 0;
}

 
