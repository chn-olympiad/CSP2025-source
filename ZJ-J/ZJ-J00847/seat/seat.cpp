#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int k=m*n;
	cin>>a[0];
	int fen=a[0];
	for(int i=1;i<k;i+=1){
		cin>>a[i];
	}
	for(int i=0;i<k;i+=1){
		for(int j=i;j<k;j+=1){
			if(a[i]<a[j]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	int wei;
	for(int i=0;a[i]!=fen;i+=1){
		wei=i;
	}
	wei+=2;
	int x=1,y=1;
	for(int i=1;i<wei;i+=1){
		if(x%2==1){
			y+=1;
			if(y==n+1){
				x+=1;
				y=n;
			}
		}
		else if(x%2==0){
			y-=1;
			if(y==0){
				x+=1;
				y=1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
