#include<bits/stdc++.h>
using namespace std;
int n,m;
struct _{
	bool xR=0;
	int num;
}a[114];
bool cheak(_ a,_ b){
	return a.num>b.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		cin>>a[(i-1)*m+j].num;
	}
	a[1].xR=true;
	sort(a+1,a+n*m+1,cheak);
	int ans;
	for(int i=1;i<=n*m;i++)
	if(a[i].xR){ans=i;break;}
	int ans2=ceil(ans*1.000/n);
	cout<<ans2<<" ";
	if(ans2%2==0)
	cout<<n*ans2-ans+1;
	else
	cout<<ans-n*(ans2-1);
}
