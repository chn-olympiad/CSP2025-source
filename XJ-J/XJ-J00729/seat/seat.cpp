#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,ans,c,r;
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
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]!=x){
			ans++;
		}
		else {
			ans++;
			break;
		}
	}
	c=ans/n;
	if(ans%n!=0)c++;
	r=ans%n;
	if(c%2==0)r=n-r+1;
	if(r==0&&c%2==0)r=1;
	if(r==0&&c%2!=0)r=n;
	cout<<c<<" "<<r;
	return 0;
} 
