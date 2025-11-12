#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","r",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=100;i++){
		i+=a;
		i++;
		cout<<i<<endl;

	}
	for(int j=0;j<=100;j++){
		j+=b;
		j++;
		cout<<j<<endl;
	}

}