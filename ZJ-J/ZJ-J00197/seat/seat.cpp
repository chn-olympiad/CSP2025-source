#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int m,n,c,r;
int a[105];
int pos[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int x=a[0];
	sort(a,a+n*m-1,cmp);
	int cnt=0,t=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			   if(a[cnt]==x){
			    	cout<<i<<' '<<j;
				    return 0;
			    }
			    cnt++;
		    }
		}
		else{
			for(int j=n;j>=1;j--){
			   if(a[cnt]==x){
			    	cout<<i<<' '<<j;
				    return 0;
			    }
			    cnt++;
		    }
		}
	}
	return 0;
}
