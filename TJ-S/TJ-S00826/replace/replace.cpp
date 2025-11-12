#include<bits/stdc++.h>
using namespace std;
int n,m;
char arr[1000005];
int pd2(int x,int y,int zx,int zy){
	if(x>y){
		if(zx+1>n/2){
			return 0;
		}else{
			return 1;
		}
	}else if(x<y){
		if(zy+1>n/2){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(zx>zy){
			return 0;
		}else{
			return 1;
		}
	}
}




int main(){
	cin>>n>>m;
	
	freopen("replace.in","r",stdin);
	
freopen("replace.out","w",stdout);

	for(int i =1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=5;i++){
		for(int j =1;j<=6;j++){
			int c = i+j*10;
		} 
	}
	if(m%2==0){
		for(int i = 1;i<=m/2;i++){
		cout<<"1"<<endl; 
	}
	for(int i = 1;i<=m/2;i++){
		cout<<"0"<<endl; 
	}
	}else{
		for(int i = 1;i<=m;i++){
		cout<<"0"<<endl; 
	}
	}
	



	return 0;
}

