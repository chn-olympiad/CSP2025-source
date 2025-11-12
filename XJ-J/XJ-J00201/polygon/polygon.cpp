#include<bits/stdc++.h> 
using namespace std;
int num[1010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>num[i];
	}
	int max=0;
	for(int i=1;i<=n*m;i++){
		if(max<num[i]){
			max=num[i];
		}
	}
	if(num[0]==max){
		cout<<"1"<<" "<<"1";
	}
	int min=1000;
	for(int i=1;i<=n*m;i++){
		if(min>num[i]){
			min=num[i];
		}
	}
	if(num[0]==min){
		cout<<"n"<<" "<<"m";
	}
	return 0;
}
