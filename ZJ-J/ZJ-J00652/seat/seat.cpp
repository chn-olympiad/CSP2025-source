#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1,cnt=1;
	while(a[cnt]!=t){
		if(y%2==1){
			x++;
			if(x>n)x--,y++;
		}
		else{
			x--;
			if(x<1)x++,y++;
		}
		cnt++;
	}
	cout<<y<<' '<<x;
	return 0;
}
