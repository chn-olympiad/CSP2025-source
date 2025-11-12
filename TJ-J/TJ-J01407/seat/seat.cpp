#include<bits/stdc++.h>
using namespace std;
#define l long long
bool cmp(int x,int y){
	return x>y;
}
int b[100000];
int main(){
	l x,y,me,x1,y1,th;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	cin>>me;
	b[1]=me;
	for(l i=2;i<=x*y;i++){
		cin>>b[i];
	}
	sort(b+1,b+x*y+1,cmp);	
	for(l i=1;i<=x*y;i++){
		if(b[i]==me){
			x1=(i-1)/x+1;
			th=i;
			break;
		}
	}
	if(x1%2==0){
		y1=x-th%x+1;
	}
	else	y1=th%x;
	if(y1==0)	y1=x;
	cout<<x1<<' '<<y1;
	return 0;
}
