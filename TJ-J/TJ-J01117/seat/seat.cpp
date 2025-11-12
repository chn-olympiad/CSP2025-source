#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	int n,c,x=n*c;
	int n1=1,c1=1;
	cin>>c>>n>>a[x];
	for(int i=1;i<=x;i++){
		//int n1=1,c1=1;
		if(a[1]>a[i]){
			break;
		}
		else{
			n1++;
			if(n1>n){
				c1++;
				n1=-1+n1-n;
			}
		}
	}
	cout<<c1<<" "<<n1;
	return 0;
}
