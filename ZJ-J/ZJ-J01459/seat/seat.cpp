#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
/*
90 pts
*/
int n,m,a[115];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+k+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=k;i++){
		if(a[i]==s){
			cout<<y<<" "<<x<<endl;
		}
		if(i%n==0){
			y++;
			continue;
		}
		if((i/n+1)%2==1){
			x++;
			continue;
		}
		if((i/n+1)%2==0){
			x--;
			continue;
		}
	}
	return 0;
}