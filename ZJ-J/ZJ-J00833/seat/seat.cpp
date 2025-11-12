#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000],k,seat_num,tol;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tol=n*m;
	for(int i=1;i<=tol;i++){
		cin>>a[i];	
	}
	k=a[1];
	sort(a+1,a+tol+1,cmp);
	for(int i=1;i<=tol;i++){
		if(a[i]==k){
			seat_num=i;
			break;
		}
	}
	int tmp=seat_num/n;
	if(tmp%2==0){
		if(seat_num%n!=0){
			cout<<tmp+1<<" "<<seat_num%n;
		}
		else{
			cout<<tmp<<" "<<1;
		}
	}
	else{
		if(seat_num%n!=0){
			cout<<tmp+1<<" "<<n-seat_num%n+1;
		}
		else{
			cout<<tmp<<" "<<n;
		}
	}
	return 0;
}
