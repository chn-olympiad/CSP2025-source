#include<bits/stdc++.h>
using namespace std;
int n,m,cja,h,l;
int cj[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int a=1;a<=n*m;++a){
		cin>>cj[a];
	}
	cja=cj[1];
	sort(cj+1,cj+n*m+1);
	for(int a=1;a<=n*m;++a){
		if(cj[a]==cja){
			cja=a;
			break;
		}
	}
	cja=n*m-cja+1;
	if(cja%n==0){
		l=cja/n;
		if(l%2==1){
			h=n;
		}else{
			n=1;
		}
	}else{
		l=cja/n+1;
		if(l%2==1){
			h=cja%n;
		}else{
			h=n-cja%n+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
