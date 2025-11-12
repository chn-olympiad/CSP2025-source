#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	int max=-1,s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		if(a[i]>max) max=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else{
		if(s>2*max){
			cout<<1;
			return 0; 
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
