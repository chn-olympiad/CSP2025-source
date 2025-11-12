#include<bits/stdc++.h>
#define ll long long
#define N 225
using namespace std;

int n,m,pt;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	pt=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	int nx=0,ny=1;
	for(int i=1;i<=n*m;i++){
		if(ny&1){
			++nx;
			if(nx>n)++ny,nx=n;
		}
		else{
			--nx;
			if(nx<1)++ny,nx=1;
		}
		if(pt==a[i]){
			cout<<ny<<" "<<nx;
			return 0;
		}
	}
	return 0;
}
