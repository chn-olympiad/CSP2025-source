#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,sum;
	cin>>n>>m;
	long long u=n*m;
	long long l;
	for(int i=1;i<=u;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+u+1,cmp);
	for(int i=1;i<=u;i++){
		if(a[i]==l){
			sum=i;
			break;
		}
	}
	long long x,y;
	if(sum%n==0){
		y=sum/n;
	}
	else{
		y=(sum/n)+1;
	}
	int h=y*m;
	if(y%2==0){
		if(h==sum){
			x=1;
		}
		else{
			x=h-sum+1;
		}
	}
	else{
		if(h==sum){
			x=n;
		}
		else{
			x=n-h+sum;
		}
	}
	cout<<y<<" "<<x;
	return 0;
} 
