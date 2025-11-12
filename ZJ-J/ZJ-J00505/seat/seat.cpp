#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[1111],po,an;
int f(int x) { 
	if(x==0) return 1;
	if(x>n) return 2*n+1-x;
	return x;
}
int main() {
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++) cin>>a[i];
	po=a[1],sort(a+1,a+c+1);
	for(int i=1;i<=c;i++) if(a[i]==po) {
		an=c+1-i;
		break;
	}
	cout<<(an-1+n)/n<<" "<<f(an%(2*n))<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}