#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tar=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1,x=0,y=1;
	while(a[k++]>=tar){
		if(y%2){
			x++;
			if(x>n){
				x=n;
				y++;
			}
		}
		else{
			x--;
			if(x<1){
				x=1;
				y++;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
//我再也不会T2忘删调试代码了 
