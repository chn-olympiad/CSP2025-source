#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int val,k;
}a[1010];
bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].k=i;
	}sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,k=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].k==1){
			cout<<y<<" "<<x;
			return 0;
		}if(x==n&&k!=-1){
			y++;
			k*=-1;
		}else if(x==1&&k==-1){
			y++;
			k*=-1;
		}else x+=k;
	}
	return 0;
}
