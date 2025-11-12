#include <bits/stdc++.h>
using namespace std;
bool cpm(int x,int y){
	return x<y;
}
//int dgshu(int )
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	int n;
//	int a[n]={};
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];	
//	}
//	sort(a+1,a+n+1,cpm);
//	for(int i=3;i<=5;i++){
//		for(int j=i;j>=1;j--){
//			
//		}
//	}
	
	
	
	
	
	
	
	
	
	
	
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a>b+c&&b>a+c&&c>a+b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
