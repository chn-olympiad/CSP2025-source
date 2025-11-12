#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[105],b[105],n,m,cnt=0,r;

bool cmp(int a,int b){
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt++];
		}
	}
	r=a[0];
	sort(a,a+cnt,cmp);
	int l=1,h=1,i=0;
	while(1){
		if(a[i]==r){
			cout<<l<<" "<<h;
			return 0;
		}
		if(l%2!=0)h++;
		if(l%2==0)h--;
		if(h>n){
			l++;h=n;
		}
		if(h<1){
			l++;h=1;
		}
		i++;
	}
	return 0;
}

