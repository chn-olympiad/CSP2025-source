#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=15;
struct node{
	int val,id;
	bool operator< (const node &a)const{
		if(val!=a.val)return val>a.val;
		return id<a.id;
	}
}a[N*N];
int n,m,tot;
pii ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)
				if(a[++tot].id==1)
					ans.fi=j,ans.se=i;
		}
		else {
			for(int i=n;i>=1;i--)
				if(a[++tot].id==1)
					ans.fi=j,ans.se=i;
		}
	}
	cout<<ans.fi<<" "<<ans.se<<'\n';
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97
*/