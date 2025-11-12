#include<iostream>
using namespace std;
int n,m,c,r,a[105],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
//	cout<<cnt<<endl;
	r=cnt/n+1;
	if(r%2==1) c=(cnt+1)%n;
	else{
		c=(n-(cnt+1)%n+1)%n;
	}
	if(c==0) c=n;
	cout<<r<<" "<<c;
	return 0;
} 
//CSP-J Journal
//8:46 Start Seat.
//     r=cnt/n+1.good.
//     c=1\ r%2==1 (r-1)*n+(cnt+1)%n
//       2\ r%2==0 r*n-(n/2-(cnt+1)%n)
//     Awesome.
//     Now Coding...
//     Oh No!WA.
//     r is correct,but c......
//9:04 It takes me a little longer than I thought.
//9:06 I totally understand that now.I'm such a Fool!
//     Now Coding......
//9:12 My Own Test Passes.Complete.
//     PUSH!
//     RP++.Luogu Bless Me!Kkksc03 Bless Me!Yifusuyi Bless Me!
//     I Love ccf! 
//10:35 Test Completed.
//11:36 Bug Fixed.
