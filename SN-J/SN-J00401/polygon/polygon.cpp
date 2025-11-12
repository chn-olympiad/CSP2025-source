#include<bits/stdc++.h>
using namespace std;
bool deal3(int x,int y,int z){
	if(x+y>z&&x+z>y&&z+y>x) return true;
	else return false;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	int cnt=0;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0"<<endl;
		return 0;
	}
	if(n==3){
		if(deal3(a[1],a[2],a[3])){
			cout<<"1"<<endl;
			
		}else cout<<"0"<<endl;
		return 0;
	}
//	if(n>3){
//		
//	}
	return 0;
} 
