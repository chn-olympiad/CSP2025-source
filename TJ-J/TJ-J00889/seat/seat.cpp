#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0];
	sort(a,a+n*m,cmp);
	int b;
	for(int i=0;i<n*m;i++){
		if(ans==a[i]){
			b=i;
			break;
		}
	}
//	cout<<b<<endl;
	int c=b/n;
	int d=b%n;
	int x,y;
	if(c%2==0){
		x=d+1;
		y=c+1;
	}else{
		x=n-d;
		y=c+1;
	}
	cout<<y<<" "<<x;
	return 0;
}

