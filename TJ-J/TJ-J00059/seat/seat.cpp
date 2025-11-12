#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return y<x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ts=a[1];
	sort(a,a+n*m,cmp);
	int jz;
	for(int i=0;i<n*m;i++){
		if(a[i]==ts){
			jz=i+2;
		}
	}
	int js=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				js++;
				if(js==jz){
					cout<<i+1<<" "<<j;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				js++;
				if(js==jz){
					cout<<i+1<<" "<<j;
				}
			}
		}
	}
	return 0;
}
