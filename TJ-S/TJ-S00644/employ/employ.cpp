#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a,b;
	long long c;
	cin>>a>>b>>c;
	int num=0;
	while(c>0){
		if(c%10==1){
			num++; 
		}
		c/=10;
	} 
	cout << num;
	return 0;
}
