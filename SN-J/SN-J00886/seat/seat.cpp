#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum,a[105];
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int b=a[1],c;
	sort(a+1,a+sum+1);
	for(int i=1;i<=sum;i++){
		if(a[i]==b){
			c=i;
		}
	}
	c=sum-c+1;
	int x=c/n;
	int y=c%n;
	if(c%n==0){
		y=n;
	}
	else
		x++;
	
	if(x%2==0){
		y=m-y+1;
	}
	cout<<x<<' '<<y;
	return 0;
}

