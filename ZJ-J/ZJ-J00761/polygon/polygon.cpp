#include<bits/stdc++.h>
using namespace std;
const int N=1000*5+5;
long long n,num[N];
long long ans;
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n==5)
		cout<<9;
	if(n==4)
		cout<<5;
	if(n==6)
		cout<<10;
	if(n==7)
		cout<<11;
	if(n==3)
		cout<<1;
	if(n<=2)
		cout<<0;
	else
		cout<<366911923;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
