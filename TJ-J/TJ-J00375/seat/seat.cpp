#include <bits/stdc++.h>
using namespace std;
void pay(int a,int b,int f) {
	int c=1,d=1;
	bool ed=1;
	for(int i=1; i<=f; i++) {
		if(c<a&&ed==1) {
			c++;
		}else if(c<a&&ed==0){
			c--;
		} else if(d<b&&ed==1) {
			d++;
			c=a;
			ed=!ed;
		}else if(d<b&&ed==0){
			d++;
			c=1;
			ed=!ed;	
		} else {
			cout<< b<<" "<<a;
		}
	}
	cout<<d<<" "<<c;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,d,cnt=0;
	cin>>a>>b;
	int as[101]= {0};
	cin>>d;
	for(int i=0; i<a*b-1; i++) {
		cin>>as[i];
		if(as[i]>d)cnt++;
	}
	pay(a,b,cnt);
	return 0;
}


