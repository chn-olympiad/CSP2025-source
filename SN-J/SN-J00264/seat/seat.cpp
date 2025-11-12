#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,rs;
int a[105],s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)rs=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,cnt=1;
	while(cnt<=n*m){
		s[i][j]=a[cnt];
		if(a[cnt]==rs){
			cout<<j<<" "<<i;
			break;
		}
		cnt++;
		if(j%2){
			if(i==n)j++;
			else i++;
		}
		else{
			if(i==1)j++;
			else i--;
		}
	}
	return 0;
}

