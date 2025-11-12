#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int d;
	int p;
}a[1001];
bool cmp(node x,node y){
	if(x.d<y.d) return false;
	else return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].d;
		a[i].p=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1){
			pos=i;
			break;
		}
	}
	int k=pos;
	if(k%m==0) k--;
	if((k/m)%2==0){
		cout<<k/m+1<<" ";
		pos=pos%m;
		if(pos==0) pos=m;
		cout<<pos;
	}
	else{
		cout<<k/m+1<<" ";
		pos=pos%m;
		if(pos==0) pos=m;
		cout<<m-pos+1;
	}
	return 0;
}
