#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,c,r,t=0;
	cin>>n>>m;
	int f=n*m;
	long long k[f];
	cin>>k[1];
	int o=k[1];
for(int i=2;i<=f;i++){
    cin>>k[i];	
}
for(int j=2;j<=f;j++){
		for(int j2=1;j2<j-1;j2++){
			if(k[j]>k[j2]){
				k[j]=k[j2];
				k[j2]=k[j];
		}
	}
}
for(int i=1;i<=f;i++){
		if(k[i]!=o){
			t++;
		}else{
			t++;
			break;
		}
}
if(t%n==0){
		c=t/n;
		cout<<c<<" "<<n;
}else{
		c=t/n;
		r=t%n;
		int p=t/n;
		if(p%3==0){
		    cout<<c<<" "<<r;
		}else{
			cout<<c<<" "<<n-r;
		}	
}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
}
