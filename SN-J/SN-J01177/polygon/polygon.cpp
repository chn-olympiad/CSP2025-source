#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,a[5005],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
    sort(a+1,a+n+1);
    if(a[1]+a[2]+a[3]>a[3]*2) ans+=1;
    cout<<ans;
	return 0;
}
