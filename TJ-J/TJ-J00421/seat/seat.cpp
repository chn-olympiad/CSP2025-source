#include<bits/stdc++.h>
using namespace std;
int n,m;
int mc,num;
int a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mc;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>mc){
			num++;
		}
	}
	int h=num/n+1;
	cout<<h<<" ";
	num%=n;
	if(h&1){
		cout<<num+1;
	}
	else{
		cout<<n-num;
	}
} 
