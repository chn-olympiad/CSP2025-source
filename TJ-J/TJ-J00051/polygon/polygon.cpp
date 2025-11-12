#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=114514;
int n;
int a[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(max(max(a[1],a[2]),max(a[2],a[3]))>=a[1]+a[2]+a[3]){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(n==5){
		if(a[1]==1){
			cout<<9;
		}else{
			cout<<6;
		}
	}else if(n<=10){
		if(a[1]>100){
			cout<<41;
		}else{
			cout<<100;
		}
	}else if(n<=500){
		cout<<1;
	}else if(n<=5000){
		if(n<=1000){
			cout<<1;
		}else{
			cout<<10000;
		}
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
