#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,num;
}a[105];
int n,m,c,r;
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			c=ceil(i*1.0/m);
			r=i%n;
			if(r==0)r=n;
			if(c%2==0){
				r=n+1-r;
			}
			break;
		}
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}

