#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int a[1001],p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	fast;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	r=a[0];
	sort(a,a+n*m,cmp);
	
	for(int i=0;i<n*m;i++){
		if(a[i]==r)p=i+1;
	}
	
	
	int y=(p+n-1)/n;
	int x;
	int tmp=p%(n*2);
	
	if(tmp<=n&&tmp!=0){
		x=tmp;
	}
	else{
		if(tmp==0)tmp=n;
		else tmp%=n;
		x=n-tmp+1;
	}
	cout<<y<<' '<<x;

	
	return 0;
} 

