#include<bits/stdc++.h>
using namespace std;
//SN-J00707 西安市曲江第一学校 
int s[12][12];
int a[144];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,cnt=0,number=0;
	int ansm,ansn;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			number=i;
		}
	}
	int r=0,c=0;
	r=number/n;
	if((number%n)!=0){
		r++;
	}
	if(r%2==1){
		if((number%n)==0){
			c=n;
		}else{
			c=number%n;
		}
	}else{
		if((number%n)==0){
			c=1;
		}else{
			c=n-(number%n)+1;
		}
	}
	cout<<r<<' '<<c;
	return 0; 
}
