#include <bits/stdc++.h>
using namespace std;
int s[105];
int xm;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >>m;
	cin >> s[1];
	xm=s[1];
	for(int i=2;i<=n*m;i++) cin >> s[i];
	sort(s+1,s+1+n*m);
	int fx=3,cs=0,i=n*m,x=1,y=1;
	while(s[i]!=xm){
		cs++;
		if(cs%n==0||cs%n==1) fx=(fx+1)%4;
		if(fx==0) y++;
		else if(fx==1) x++;
		else if(fx==2) y--;
		else if(fx==3) x++;
		i--;
	}
	cout << x << " " << y;
	return 0;
}
