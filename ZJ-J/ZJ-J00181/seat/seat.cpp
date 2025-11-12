#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define PQ priority_queue
const int N=5;
int a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		cnt++;if(a[i]==t)break;
	}
	t=cnt%m;
	cnt/=m;
	if(!t){
		cout<<cnt;
		t=m;
	}
	else cout<<++cnt;
	cout<<" ";
	if(cnt%2)cout<<t;
	else cout<<m-t+1;
	return 0;
}

