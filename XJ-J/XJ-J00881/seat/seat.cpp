#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL long long
const int N=1e3+5;
LL n,a[N],m,r,cnt=1,row,col;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r){
			cnt++;
		}
	}
	int col=ceil(1.0*cnt/n);
	if(col%2==0){
		if(cnt%n==0){
			row=1;
		}
		else row=n-cnt%n+1;
	}
	else {
		if(cnt%n==0)row=n;
		else row=cnt%n;
	}
	cout<<col<<' '<<row;
	return 0;
} 
