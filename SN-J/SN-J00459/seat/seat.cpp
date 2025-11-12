#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[10005];
void turn(int x,int y){
	int c=0;
	for(int i=x;i<=y;i++){
		if(a[i]<a[i+1]){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
	}
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;	
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	long long t=a[1];
	turn(1,1+sum+1);
	long long num=0;
	for(int i=1;i<=sum;i++){
		if(a[i]==t){
			num=i;
		}
	}
	int tot=0;
	if(num%m==0){
		tot=num/m;
	}
	else{
		tot=num/m+1; 
	}
	if(tot%2==0){
		cout<<tot<<" "<<m-num%m+1;
	}
	else{
		cout<<tot<<" "<<num%m;
	}
	return 0;
	
}
