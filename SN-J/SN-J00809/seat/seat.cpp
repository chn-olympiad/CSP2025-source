//SN-J0809 王锦铭 曲江第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int s=m*n,w=1,f=1;
	int a[s];
	for(int i=1;i<s;i++){
		cin>>a[i];
	}
	if(a[1]=1 and a[2]>a[1]){
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i=1;i<=s;i++){
		if(a[i]==n*m-i+1 and a[i+1]<a[i]){
			cout<<"1"<<" "<<"1";
			return 0;
		}
	}
	return 0;
}

