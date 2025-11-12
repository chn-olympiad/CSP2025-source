#include <bits/stdc++.h>
using namespace std;
int check(int n){
	int m=0;
	while(n!=0){
		n/=10;
		m++;
	}
	return m;
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int a;
	cin>>a;
	int z=check(a);
    int ans[10];
    for(int i=1;i<=z;i++){
    	ans[i]=a%10;
    	a/=10;
	}
	sort(ans+1,ans+z+1);
	for(int i=z;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
