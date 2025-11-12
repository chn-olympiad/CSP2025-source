#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[30][30];
int s[1000];
int R;
int seat_R;
int ans_n,ans_m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int lenth=n*m;
	for(int i=1;i<=lenth;i++){
		cin>>s[i];
	}
	R=s[1];
	sort(s+1,s+1+lenth,cmp);
	for(int i=1;i<=lenth;i++){
		if(s[i]==R) seat_R=i;
	}
	ans_m=seat_R/n;
	if(seat_R%n!=0)  ans_m++;
	if(ans_m%2==1) ans_n=seat_R%n;
	else ans_n=n-seat_R%n+1;
	if(ans_n==0) ans_n=n;
	cout<<ans_m<<" "<<ans_n;
	return 0;
} 
