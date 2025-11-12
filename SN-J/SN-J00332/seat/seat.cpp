#include<bits/stdc++.h>
using namespace std;
int n,m,fid;
struct node{
	int val,id;
}a[1005];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			fid=i;
			break;
		}
	}
	int ls=(fid-1)/(2*n)+1;
	int sy=fid-(ls-1)*2*n;
//	cout<<ls<<" "<<sy<<"\n";
	if(sy<=n){
		cout<<((ls-1)*2)+1<<" "<<sy<<"\n";
	}
	else{
		cout<<ls*2<<" "<<2*n-sy+1<<"\n";
	}
	return 0;
}
