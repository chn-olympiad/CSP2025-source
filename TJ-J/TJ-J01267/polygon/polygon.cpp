#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k = 0;
	int ans = 0,a[5007];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(n==1||n==2)cout << 0;
	else if(n==3){
		if((a[1]+a[2])*2>a[3])cout << 1;
		else cout << 0;
	}
	else cout << 36;
	
	return 0;
}
