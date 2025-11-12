#include<bits/stdc++.h>
using namespace std;
int n,m;
void ch(int w){
	int l=(w+n-1)/n;
	int h=(w+n-1)%n+1;
	if(l%2==0){
		h=n+1-h;
	}
	cout<<l<<" "<<h;
}
struct node{
	int v,id;
}a[105];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			ch(i);
			exit(0);
		}
	}
	return 0;
}

