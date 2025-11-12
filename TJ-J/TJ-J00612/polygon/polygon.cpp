#include<iostream>
using namespace std;
int n,a[5000005],x,y,A;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>A) A=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=i;l<=j;l++){
				x+=a[l];
			}
			if(x>A*2) y++;
			x=0;
		}
	}
	cout<<y;
	return 0;
}
