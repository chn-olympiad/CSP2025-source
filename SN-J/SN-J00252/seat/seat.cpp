#include<bits/stdc++.h>
using namespace std;
long long x,y,a[102],cnt=1;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
		cnt++;
	}
	int b=a[1],c,d;
	for(int j=1;j<=cnt-2;j++){
		for(int k=j+1;k<=cnt-1;k++){
			if(a[j]<a[k]){
				swap(a[j],a[k]);
			}
		}
	}
	for(int i=1;i<=cnt-1;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if(c%y==0){
		d=c/y;
	}else{
		d=c/y+1;
	}
	c=c%(2*y);
	if(c>y){
		cout<<d<<" "<<y-(c-y)+1;
	}
	else{
		cout<<d<<" "<<c;
	}
	return 0;
}
