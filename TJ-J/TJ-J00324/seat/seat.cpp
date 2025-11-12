#include <bits/stdc++.h>
using namespace std;
const int MAX=105;
int a[MAX];
int ans,sum,num,s,z,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<=n*m;j++){
			ans=max(a[j],ans);
		}
		sum++;
		for(int j=0;j<=n*m;j++){
			if(ans==a[1]){
				num=sum;
			}
			if(ans==a[j]){
				a[j]=0;
				break;
			}
			
		}
		ans=0;
	}
	s=num/n;
	if(num%n==0){
		y=s;
		x=n;
		cout<<y<<" "<<x;
		return 0;
	}
	else{
		y=s+1;
		z=num%n;
	}
	if(y%2!=0){
		x=z;
	}
	else{
		x=n-z+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
