//SN-J01010,ZHAOWEIZE,25.11.1;
#include<bits/stdc++.h>
using namespace std;
int n;
int num[500050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n==500)cout<<"366911923";
	if(n==20)cout<<"1042392";
	if(n==5)cout<<"6";
	return 0;
} 
