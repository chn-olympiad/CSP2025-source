//	SN-J00234  姚棕严  西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int s=0;
	
	if(a[1]+a[2]>max(a[1],a[2])*2){
		s++;
	}else if(a[1]+a[3]>max(a[1],a[3])*2){
		s++;
	}else if(a[2]+a[3]>max(a[2],a[3])*2){
		s++;
	}else if(a[1]+a[3]+a[2]>max(a[2],max(a[1],a[3]))*2){
		s++;
	}
	
	cout<<s;
	
	return 0;
}
