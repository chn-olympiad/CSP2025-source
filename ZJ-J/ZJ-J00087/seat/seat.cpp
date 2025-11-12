#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
struct str{
	int a,i;
}d[N];
bool cmp(str a,str b){
	return a.a>b.a;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q,x,c,r;
	cin>>n>>m;
	q=n*m;
	for(int i=0;i<q;i++)cin>>d[i].a,d[i].i=i;
	sort(d+1,d+q+1,cmp);
	for(int i=0;i<q;i++){
		if(d[i].i==1){
			x=i;
			break;
		}
	}
	c=x/n+1;
	if(c&1)r=x%n+1;
	else r=n-x%n;
	cout<<c<<' '<<r<<endl;
	return 0;
}
//de li xiu si,miao
