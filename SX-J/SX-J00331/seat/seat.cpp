#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int s[n][m];
	int c,r;
	int b[1000];
	for(int i=0;i<m*n;i++){
		int a;
		cin>>a;
		b[i]=a;
	}

	for(int j=0;j<m*n;j++){
  		cout<<b[j]<<endl;
	}
	return 0;
}



