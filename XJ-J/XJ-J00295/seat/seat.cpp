#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001],b,x,t=1,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
    	if(a[i]==b){
    		b=i;
    		break;
		}
}
    while(b>n){
    	b=b-n;
    	t++;
	}
	if(t%2==1){
		x=b;
	}
	else if(t%2==0){
		x=n-b+1;
	}
	cout<<t<<" "<<x;
	return 0;
}
