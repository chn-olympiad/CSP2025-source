#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int a[102],a1,s;
	for(int i=0;i<n*m;i++)cin>>a[i];
	a1 = a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			s = i+1;
			break;
		}
	}
	int c = ceil(s*1.0/n);
	int r = s%n;if(r==0)r=n;if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}
