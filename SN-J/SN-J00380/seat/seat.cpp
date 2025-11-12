#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int sc;
};
int mainid;
node a[105];
int m,n;
int c=1,r=0,ctj=0,rtj=0;
bool op=true;
node x,y;
bool camp(node x,node y){
	return x.sc>y.sc; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+m*n+1,camp);
	for(int i=1;i<=m*n;i++){
		if(a[i].id==1){
			mainid=i;
			break;
		}
	}
	for(int i=1;i<=mainid;i++){
		rtj++;
		if(rtj==n){
			c++;
			rtj=0;
		}
		if(r==1&&op==false){
			op=true;
			r--;
		}
		if(r==n&&op==true){
			op=false;
			r++;
		}
		if(op==true){
			r++;
		}
		if(op==false){
			r--;
		}
		
	}
	if(n==1){
		r=1;
	}
	if(m==1){
		c=1;
	}
	
	cout<<c<<" "<<r; 
	return 0;
}
