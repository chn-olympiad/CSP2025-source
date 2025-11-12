#include<bits/stdc++.h>
using namespace std;
int n,m,r,w,x,y,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	int a[s+5];
	for (int i=0;i<s;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+s+1);
	for (int i=0;i<s;i++)
	{
		if(a[i]==r){
			w=i;
			break;
		}
    }
    w=s-w;
    if(x%n==0){
    	x=w/n;
	}else{
    	x=w/n+1;	
	}
	if(x%2==1){
		y=w%(n*2);
	}else{
		y=n-w%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
