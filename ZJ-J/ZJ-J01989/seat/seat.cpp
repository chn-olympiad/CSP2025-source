#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long x,id;
}a[105];
bool cmp(Node t1,Node t2){
	return t1.x>t2.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	long long nid=0;
	for(long long i=1;i<=n*m;i++){
		if(a[i].id==1){
			nid=i;
			break;
		}
	}
	long long wy=0,wx=0;
	wy=(nid+n-1)/n;
	if(wy%2==1) wx=nid-(wy-1)*n;
	else wx=n+1-(nid-(wy-1)*n);
	cout<<wy<<" "<<wx<<endl;
	return 0;
}
