#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int res=a[1],v;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==res){
			v=i;
			break;
		}
	}
	int y=(v-1)/n+1,x;
	if(y&1) x=v-n*(y-1);
	else x=m-v+n*(y-1)+1;
	cout<<y<<' '<<x;
	return 0;
}