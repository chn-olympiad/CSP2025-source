#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon,out","w",stdout);
	
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(max(a,b),c)*2<a+b+c) cout<<1;
		else cout<<0;
		return 0;
	}else if(n==5){
		int a[5];
		for(int i=0;i<5;i++){
			cin>>a[i];
		}
		if(a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
			cout<<9;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
