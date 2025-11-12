#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<vector>
int a[105];
int Rgrade;//Ð¡RµÄ³É¼¨
bool cmp(int x,int y){
	return x>y;
}
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,S,c,r,seat;
	cin>>n>>m;
	S=n*m;
	cin>>Rgrade;
	for(int i=2;i<=S;i++){
		cin>>a[i];
	}
	a[1]=Rgrade;
	sort(a+1,a+S+1,cmp);
	int l=1;r=S;
	for(int i=1;i<=S;i++){
		if(a[i]==Rgrade){
			seat=i;
			break;
		}
	}
	c=(seat+n-1)/n;
	if(c&1) r=seat-c*n+n;
	else r=c*n-seat+1;
	cout<<c<<' '<<r;
	return 0;
}

