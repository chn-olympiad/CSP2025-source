#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int max=-1;
	int s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		if(a[i]>max) max=a[i];
	}
	if(n<3){
		cout<<"0";
	}
	if(n==3 && max*2 < s){
		cout<<"1";
	}
	if( n>=3 && max*2>=s){
		cout<<"0";
	}
	return 0;
}
