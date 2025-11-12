#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
struct stu{
	int v,id;
	bool operator<(const stu&o)const{return v>o.v;}
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>a[i].v,a[i].id=i;
	sort(a+1,a+n*m+1);
	for(int i = 1;i<=n*m;i++){
		if(a[i].id!=1) continue;
		int c = (i+n-1)/n,r;
		if(c%2) r = i-n*(c-1);
		else r = n*c-i+1;
		cout<<c<<' '<<r;
		return 0;
	}
	return 0;
}
