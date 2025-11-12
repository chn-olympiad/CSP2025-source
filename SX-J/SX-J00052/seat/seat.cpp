#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001],i=0,x=1,y=1,my;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<=n*m;i++){
		cin>>a[i];
	}
	my=a[0];
	sort(a,a+i);
	long long a1[n+1][m+1];
	for(int j=i-1;j>=0;j--){
		if(a[j]==my){
			cout<<y<<" "<<x;
			break;
		}
		//cout<<y<<" "<<x;
		if(y%2==1){
			if(x==n)y++;
			else x++;
		}
		else {
			if(x==1)y++;
			else x--;
		}


	}

}
