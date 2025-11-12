#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	bool p;
}a[125];
int n,m;
int p;
bool cmp(node a,node b){
	return a.s>b.s;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].p=(i==1);
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].p){;
			p=i;
			break;
		}
	}int t=(p-1)/n+1,h=(p-1)%n+1;
	if(t%2==0) h=n-h+1;
	cout<<t<<" "<<h;
	return 0;
}
