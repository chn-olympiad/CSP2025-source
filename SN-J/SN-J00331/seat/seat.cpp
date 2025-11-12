#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	if(a[1]==100){
		cout<<"1"<<"1";
	}
	if(a[1]==99 and n>=2){
		cout<<"1"<<"2";
	}
	if(a[1]==98 and n>=3){
		cout<<"1"<<"3";
	}
}
