#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s=1,e,d=1,f;
	cin>>m>>n;
	cin>>f;
	for(int i=1;i<=m*n-1;i++){
		cin>>e;
		if(f<e){
			s=s+1;	 
		}
	}
	for(int y=0;y<=s;y++){
		y>m;
		d=d+1;
	}
	if(s<=m){
		cout<<1<<" "<<s;
	}else if(d%2==0){
		cout<<d-2<<" "<<m-(m*n-s);
	}else if(d%2!=0){
		cout<<d/2-1<<" "<<m-(m*n-s);
	}
} 
