//XTBT
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+5;
int n,m,t;
int a[maxn];
bool cmp(int x,int y){
	return x>y;
}
signed main()
{ 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			k=i;break;
		}
	}
	int l=(k+n-1)/n;
	int r=k-(l-1)*n;
	if(l%2==0)r=n-r+1;
	cout<<l<<" "<<r<<endl;
	
	return 0;
}

