#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node{
	long long x,y;
} a[100010];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	double c=n,d=m;
	for(int j=1;j<=n*m;j++){
		cin>>a[j].x;
		a[j].y=j;
	}	
	sort(a+1,a+n*m+1,cmp);
	double x=0.0;
	for(int j=1;j<=n*m;j++){
		if(a[j].y==1){
			x=j;
			break;
		}
	}
	int l=ceil(x/c);
	int h=int(x)%int(c);
	if(h==0){
		h=c;
	}
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
