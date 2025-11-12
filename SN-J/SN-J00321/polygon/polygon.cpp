#include<bits/stdc++.h>
using namespace std;
int l[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>l[i];
		a=l[0];
		b=l[1];
		c=l[2];
	}
	if(a+b>c&&b+c>a&&a+c>b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
 
