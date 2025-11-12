#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=1e9+7;
struct node{
	int x;
	int id;
};
int n,m;
node a[200];
bool cmp(node x,node y){
	return x.x>y.x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int t=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			t=i;
			break;
		}
	}
	int ans1=t/n+bool(t%n);
	cout<<ans1<<' ';
	if(ans1%2==1){
		int ans2=(t%n==0)?n:t%n;
		cout<<ans2<<endl;
	}else{
		int ans2=(t%n==0)?n:t%n;
		cout<<n-ans2+1<<endl;
	}
	return 0;
}
//pts 100
//Shan
