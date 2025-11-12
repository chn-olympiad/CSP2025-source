#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s;
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	int d;
	for(int i=1;i<n*m;i++){
		if(a[i]==s){
			int op=0;
			if(i<=n&&op==0) d=1,op=1;
			else if(i<=2*n&&op==0) d=2,op=1;		
			else if(i<=3*n&&op==0) d=3,op=1;		
			else if(i<=4*n&&op==0) d=4,op=1;		
			else if(i<=5*n&&op==0) d=5,op=1;		
			else if(i<=6*n&&op==0) d=6,op=1;		
			else if(i<=7*n&&op==0) d=7,op=1;		
			else if(i<=8*n&&op==0) d=8,op=1;		
			else if(i<=9*n&&op==0) d=9,op=1;		
			else if(i<=10*n&&op==0) d=10,op=1;		
			if(d%2==0){
				cout<<d<<" "<<(d-1)*n;
				return 0;
			}else{
				cout<<d<<" "<<i-(d-1)*n;
			}
		}	
	}
	return 0;
}
