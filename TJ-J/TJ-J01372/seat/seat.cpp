#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d[1000000],x,y;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>a>>b;
	if(a==1 and b==1){
		cout<<1<<" "<<1;
		return 0;
	}
for(int i=1;i<=a*b;i++){
	cin>>d[i];
}
for(int i=2;i<=a*b;i++){
	if(d[i]>d[1]){
		c++;
	}
}
c++;
if(a==1){
	cout<<c<<" "<<1;
	return 0;
}
if(b==1){
	cout<<1<<" "<<c;
}
if(c%a==0){
	if((c/a)%2==1){
		cout<<(c/a)<<" "<<a;
	}
	if((c/a)%2==0){
		cout<<(c/a)<<" "<<1;
	}
	return 0;
}
if((c-1)%a==0){
if((c/a)%2==1){
		cout<<((c-1)/a)+1<<" "<<a;
	}
	if(((c-1)/a)%2==0){
		cout<<((c-1)/a)+1<<" "<<1;
	}
	return 0;	
}
x=c/a;
x++;
y=c%a;
	if(x%2==1){
		cout<<x<<" "<<y;
	}
	if(x%2==0){
		cout<<x<<" "<<a-y+1;
	}
	return 0;
} 
