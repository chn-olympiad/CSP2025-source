#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[110];
int nxtx(int x,int y){
	//x-n-h  y-m-l
	
	if(y%2==1){
		if(x==n){
			return x;
		}else{
			//cout<<"_";
			return x+1;
		}
	}
	if(y%2==0){
		if(x==1){
			return x;
		}else{
			//cout<<"^";
			return x-1;
		}
	}
}
int nxty(int x,int y){
	if((y%2==0&&x==1)||(y%2==1&&x==n)){
		//cout<<">";
		return y+1;
		
	}
	return y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int kkk=n*m;
	for(int i=1;i<=kkk;i++){
		scanf("%d",&arr[i]);
	}
	int R=arr[1];
	int nx=1,ny=1;
	sort(arr+1,arr+kkk+1);
	int p=0;
	for(int i=kkk;i>=1;i--){
		if(arr[i]==R){
			break;
		}
		p++;
	}
	while(p--){
		int nnx=nxtx(nx,ny);
		int nny=nxty(nx,ny);
		nx=nnx;
		ny=nny;
	}
	cout<<ny<<" "<<nx;
	return 0;
}
