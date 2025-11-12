#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct node{
	int a,id;
	friend bool operator<(const node a,const node b){
		return a.a>b.a;
	}
}l[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	l[1].id=1;
	for(int i=1;i<=n*m;i++){
		cin>>l[i].a;
	}
	sort(l+1,l+1+n*m);
	int cnt;
	for(int i=1;i<=n*m;i++){
		if(l[i].id==1){
			cnt=i;
			break;
		}
	}
	int x,y;
	if(cnt%n==0){
		x=cnt/n;
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}else{
		x=(cnt/n)+1;
		int z=cnt%n;
		if(x%2==0){
			y=n-z+1;
		}else{
			y=z;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
