#include<iostream>
using namespace std;
int n,m,nums[101],cj=0;
int seatt(int pm,int n,int m,int time){
	int x=pm/n,y=pm%n;
	if(x%2==0){
		if(y==0){
			y=1;
		}else{
			y+=0;
			x++;
		}
	}else{
		if(y==0){
			y=n;
		}else{
			y=m-y-1;
			x++;
		}
	}
	cout<<x<<' '<<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nums[n*m+1];
	for(int i=0;i<n*m;i++){
		cin>>nums[i];
	}int cj=nums[0],flag=n*m,pm=0,k=0;
	for(int i=0;i<flag;i++){
		if(nums[k]>=cj){
			pm++;
		}k++;
	}seatt(pm,n,m,0);
	return 0;
}

