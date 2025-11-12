#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[105];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int a=0;a<n*m;a++){
		cin>>arr[a];
	}
	int R=arr[0];
	sort(arr,arr+n*m,cmp);
	int x=1,y=1;
	for(int a=0;a<n*m;a++){
		if(x==n+1&&y%2!=0){//奇换偶 
			y++;
			x--;//多的减掉 
		}
		else if(x==0&&y%2==0){//偶换奇 
			y++;
			x++;//少的加上 
		}
		
		if(arr[a]!=R){
			if(y%2!=0){
				x++;
			}
			else{
				x--;
			}
		}else{
			cout<<y<<" "<<x;//输出列行 
			return 0;
		}
	}
	return 0;
} 
