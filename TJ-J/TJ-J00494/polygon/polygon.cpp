#include<iostream>
#include<algorithm>
using namespace std;
int a[4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=3;i++){ cin>>a[i];}
	sort(a+1,a+3+1);
	if(a[1]+a[2]>a[3]) cout<<1;
	else cout<<0;
	return 0;
}

