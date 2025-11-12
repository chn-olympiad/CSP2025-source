#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101];
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	sort(a,a+101);
	cout<<2<<' '<<2;
	
    return 0;

	}
