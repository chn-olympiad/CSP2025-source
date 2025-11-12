#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,k=1;
const long long N=1e2+10;
int a[N]={0};
int q[N]={0};
long long g=0,b=0,c=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long s=a[1];
	sort(a+1,a+(m*n)+1);
	
	for(int i=n*m;i>0;i--){
		q[k++]=a[i];
		
	}
	for(int i=1;i<=n*m;i++){
		if(q[i]==s){
			 g=i;
			 
			 break;
		}
	}
	
	if(g%n!=0){
		b=g/n+1;
	}else{
		b=g/n;
	}
	if(b%2==1){
		c=g%n;
		if(c==0){
			c=n;
		}
	}else{
		if(g%n!=0){
			c=n-(g%n)+1;
		}else{
			c=1;
		}
		
		
		
	}
	cout<<b<<' '<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

