#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int temp,dis;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)temp=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<' ';
		if(a[i]==temp)dis=i;
	}
	int x=(dis-1)/n+1,y;
	if(x%2!=0)y=dis-(x-1)*n;
	else y=n-(dis-(x-1)*n)+1;
	cout<<x<<' '<<y;
	return 0;
}
