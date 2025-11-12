#include <bits/stdc++.h>
using namespace std;
int a[105],x,n,m,s[15][15];
void ddd(int i,int j,int cnt){
	s[i][j] = a[cnt++];
	//cout<<j<<" "<<i<<" "<<s[i][j]<<"\n";
	if(s[i][j] == x){
		cout<<j<<" "<<i;
		return;
	}
	if(cnt-1 == n*m) return;
	else if(j%2){
		if(i == n) ddd(i,j+1,cnt);
		else ddd(i+1,j,cnt);
	}else{
		if(i == 1) ddd(i,j+1,cnt);
		else ddd(i-1,j,cnt);
	}
}
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
//	cout<<n<<" "<<m<<"\n";
	ddd(1,1,1);
	return 0;
}

