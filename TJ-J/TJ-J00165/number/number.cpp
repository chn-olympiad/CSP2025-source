#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>b[j];
	}
	for(int j=1;j<=n;j++){
		if(b[j]==1&&b[j]==2&&b[j]==3&&b[j]==4&&b[j]==5&&b[j]==6&&b[j]==7&&b[j]==8&&b[j]==9 ){
			b[j]=b[j];
		}
		if(b[j]>b[j+1]){
			b[j]=b[j]*10+b[j+1]*1;
		}
		cout<<b[j];
	}
	return 0;
}

