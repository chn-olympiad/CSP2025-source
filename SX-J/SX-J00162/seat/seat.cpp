#include<iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,m,a[1000],b[1000][1000],ans=0;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
	}
	sort(a,a+num-1);
	for(int c=1;c<=m;c++){
		for(int i=1;i<=num;i++){
		if(c%2!=0){
			for(int r=1;r<=n;r++){
				b[r][c]=a[i];
				if(b[r][c]==a[1]){
					cout<<c<<" "<<r;
					break;
				}
			}
		}else if(c%2==0){
			for(int r=1;r>=n;r--){
				b[r][c]=a[i];
				if(b[r][c]==a[1]){
					cout<<c<<" "<<r;
					break;
				}
			}
		}
	}
	}
	return 0;
}