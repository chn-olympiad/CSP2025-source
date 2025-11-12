#include<iostream>
using namespace std;
int n,m,a[199],t[109]={0};
int d=a[0],s=0;
int main(){
	freopen("std","r",seat.in);
	freopen("std","w",seat.out);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		t[a[i]]=1;
	}
	for(int j=100;j>=0;j++){
		if(t[j]==1){
			s++;
			if(j==d){
				cout<<s;
				break;
			}
		}
	}
	int s1=s%n,s2=s/n,s3=n-s1+1;
	if(s1>0){
		s2++;
		if(s2%2!=0){
			cout<<s2<<" "<<s1;
		}else{
			cout<<s2<<" "<<s3;
		}
	}else{
		if(s2%2!=0){
			cout<<s2<<" "<<n;
		}else{
			cout<<s2<<" "<<1;
		}
	}
	return 0;
}
