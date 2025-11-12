//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])cnt++;
	}
	int x=cnt/n+1,y=cnt%n;
	if(y==0)y=n,x--;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
