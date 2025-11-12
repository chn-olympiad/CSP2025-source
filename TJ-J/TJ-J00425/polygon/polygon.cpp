#include<iostream>
using namespace std;
int a[5000],n,all=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=0,count=0;
	if(n==3){
		for(int i=0;i<3;i++){
			if(a[i]>max){
				max=a[i];
			}
			count+=a[i];
		}
		if(count>max*2){
			all++;
		}		
	}
	cout<<all;
	return 0;
} 
