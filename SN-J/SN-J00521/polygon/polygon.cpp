#include<bits/stdc++.h>
using namespace std;
int main(){
	spreopen("polygon.in""r"stdin);
	spreopen("polygon.out""w"stdin);
	int s[1000000]={};
	int m=0;
	for(int i;i<=1000000;i++){
		cin>>s[i];
		if(s[i]>=1&&s[i]<=9){
			m=m+s[i];
		}
	}
	cout<<m;
	return 0;
}
