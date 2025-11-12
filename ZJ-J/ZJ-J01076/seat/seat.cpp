#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
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
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	if(t%n==0){
		cout<<t/n<<' '<<(t/n%2?n:1);
		return 0;
	}
	cout<<t/n+1<<' '<<(t/n%2?n-t%n+1:t%n);
	return 0;
}
