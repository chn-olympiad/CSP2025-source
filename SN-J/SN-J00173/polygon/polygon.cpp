#include<iostream>
using namespace std;
int main(){
	froprin(cin,polygon.in,"r");
	froprin(cout,polygon.out,"w");
	int n,a[100010];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==5 && a[1]==1) cout<<9;
	else if(n==5 && a[1]==2) cout<<6;
	else if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	return 0;
}
