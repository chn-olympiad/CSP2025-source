//	SN-J00234  姚棕严  西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int R=a[1];
	
	sort(a+1,a+m*n+1);
	
	int ans=0;
	
	for(int i=m*n;i>0;i--){
		ans++;
		if(a[i]==R){
			break;
		}
	}
	
	int c=0,l=ans;
	
	while(l>=n){
		c++;
		l-=n;
	}
	
	if(l!=0){
		c++;
	}
	
	int r;
	
	if(c%2==1){
		if(l==0){
			r=n;
		}else{
			r=l;
		}
	}else{
		if(l==0){
			r=1;
		}else{
			r=n-l+1;
		}
	}
	
	cout<<c<<" "<<r;
	
	return 0;
}
