#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int x=1,y=1,d=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			if(d==1){
				if(y+d<=n)y++;
				else{
					x++;
					d=-1;
				}
			}else{
				if(y+d>=1)y--;
				else{
					x++;
					d=-1;
				}
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
