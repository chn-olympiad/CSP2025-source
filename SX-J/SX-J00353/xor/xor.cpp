#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","r",stdout);
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