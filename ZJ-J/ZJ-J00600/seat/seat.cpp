#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);//排序 
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) x=i;
	}
	//cout<<"x:"<<x<<endl;
	if(x%m!=0) c=x/m+1;
	else c=x/m;
	if(c%2==1){
		r=x%m;
		if(r==0) r=n;
	}
	else r=n+1-(x%m);
	cout<<c<<" "<<r;
	return 0;
} 