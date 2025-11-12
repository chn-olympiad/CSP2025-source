#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,t=1,r,h,l;//nÐÐmÁÐ 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	for(int i=1;i<=n*m-1;i++){
		int x;
		cin >> x;
		if(x>r){
			t++;
		}
	}
	l=(t+m-1)/n;
	if((t-1)/m % 2 == 0){
		h = (t+m-1)%m+1;
	}else{
		h = m-(t+m-1)%m;
	}
	cout << l << ' ' << h; 
	return 0;
}
