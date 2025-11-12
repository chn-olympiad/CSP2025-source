#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],aa,z=1,w=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}aa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;;i++){
		if(a[i]==aa){
			break;
		}
		if(z%2&&w==n)z++;
		else if(z%2==0&&w==1)z++;
		else if(z%2)w++;
		else w--;
	}
	cout<<z<<' '<<w;
	return 0;
}
