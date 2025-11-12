#include <iostream>
#include <algorithm> 
using namespace std;

int n, m, now, a[200];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	now=a[1];
	sort(a+1, a+n*m+1, cmp);
	int pos;
	for(int i=1; i<=n*m; i++){
		if(a[i]==now){
			pos=i;
			break;
		}
	}
	cout << pos << endl;
	int  r, c;//rÁÐ cÐÐ 
	r=((pos-1)/n)+1;
	c=((pos-1)%n)+1;
	if(r%2==0){
		c=n+1-c;
	}
	cout << r << ' ' << c;
	return 0;
}
