#include<bits/stdc++.h>
using namespace std;
int cjpx[105];
bool cmp(int x,int y){
	return x>y;
}
int ls,hs,n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int xrcj;
	cin >> xrcj;
	cjpx[1]=xrcj;
	for(int i = 2;i<=n*m;i++){
		cin >> cjpx[i];
	}
	sort(cjpx+1,cjpx+n*m+1,cmp);
	int xrcjpw = 0;
	for(int i = 1;i<=n*m;i++){
		if(cjpx[i]==xrcj){
			xrcjpw = i;
		}
	}
	if(n==1||m==1){
		if(n==1){
			cout << xrcjpw << " " << 1;
		}else{
			cout << 1 << " " << xrcjpw;
		}
	}else{
		ls = (xrcjpw+1)/n;
		if((xrcjpw-1)%n==0){
			ls = (xrcjpw+2)/n;
		}
		hs = xrcjpw-n*(ls-1);
		if(ls%2==0){
			hs = n-hs+1;
		}
		cout << ls << " " << hs;
	}
	return 0;
}