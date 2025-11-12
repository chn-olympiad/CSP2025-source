#include<bits/stdc++.h>
using namespace std;
int n,m,goal[105],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> goal[i];
		if(goal[i]>goal[1]) cnt++;
	}
	if(cnt%n==0){
		cout << cnt/n << ' ';
		if((cnt/n)%2==0) cout << 1;
		else cout << n;
	}else{
		cout << cnt/n+1 << ' ';
		if((cnt/n+1)%2==0) cout << n-cnt%n+1;
		else cout << cnt%n;
	}
	return 0;
}

