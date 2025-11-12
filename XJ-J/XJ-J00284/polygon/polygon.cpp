#include<bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,a[1000],z=0;
	cin>>n;
	int d=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[0]+a[1]+a[n-i]>2*a[n-i]){
			cout<<(n-i)*(n-i-1);
			break;
		}
	}
	//fclose("polygon.in");
	//fclose("polygon.out");
	return 0;
}
