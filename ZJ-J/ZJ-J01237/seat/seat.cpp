#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			num=i;
			break;
		}
	}
	int x=num/n;
	if(x*n!=num) x++;
	int y=num%n;
	if(y==0) y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
