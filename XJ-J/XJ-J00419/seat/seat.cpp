#include <bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000000]={0};
int main(){
	//freopen("seat1.in","r",stdin);
	//freopen("seat1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1=0;
	cin>>a1;
	a[0]=a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}

	for(int i=0;i<n*m;i++){
		b[a[i]]++;
	}
	
	int cnt=0;
	for(int i=101;i>=0;i--){
		if(b[i]!=0){
			a[cnt]=i;
			cnt++;
		}
	}
	
	int r=0;
	for(int i=0;i<n*m;i++){
			if(a[i]==a1){
				r=i+1;
		}
	}
	
	
	int x,y=0;
	if((r/n+1)%2==0){
		y=r%(2*n);
	}
	y=r%(2*n); 
	
	if(r%n==0){
		x=r/n;
	}else{
		x=r/n+1;
	}
		
	

cout<<x<<" "<<y;
return 0;
}
