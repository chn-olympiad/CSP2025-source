#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],rnk=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])rnk++;
	}x=(rnk-1)/n+1;
	if(x%2==0)y=n-(rnk-1)%n;
	else y=(rnk-1)%n+1;
	cout<<x<<" "<<y;
	return 0;
}
