#include<bits/stdc++.h>
using namespace std;
long long a[10];
char n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>n){
		if(n>='0' and n<='9'){
			a[n-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
