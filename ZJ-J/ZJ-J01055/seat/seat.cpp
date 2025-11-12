#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
struct node{
	int b,v;
}a[1100];
bool cmp(node x,node y){
	return x.v>y.v;
}
void find(int st){
	int h=st%n;
	int l=st/n;
	if (h!=0) l++;
	if (l%2==0){
		if (h==0){
			cout<<l<<" "<<1;
			return;
		}
		cout<<l<<" "<<n-h+1;
	}
	else {
		if (h==0){
			cout<<l<<" "<<n;
			return;
		}
		cout<<l<<" "<<h;
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].b=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int st;
	for(int i=1;i<=n*m;i++){
		if (a[i].b==1){
			st=i;
			break;
		}
	}
	find(st);
	return 0;
}
