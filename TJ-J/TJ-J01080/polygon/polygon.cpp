#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	long long x;
	for(int i=1;i<=n;i++){
		x=(2*x)%998244353;
	}
	x-=1;
	cout<<x/3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
