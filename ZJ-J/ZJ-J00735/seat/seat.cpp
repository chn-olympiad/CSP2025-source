#include<bits/stdc++.h>
using namespace std;
int n,m,k[15][15],a[105],r,key;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1],key=n*m;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;){
		for(int j=1;j<=n;){
			if(a[key]==r){
				cout<<i<<' '<<j;
				return 0;
			}
			key--;
			if((i%2==0&&j==1)||(i%2==1&&j==n))i++;
			else{
				if(i%2==1)j++;
				else j--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}