#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,p=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
		    for(int k=i;k<=j;k++){
				p+=a[k];
				if(p>2*a[j]){
					ans++;
				}
			}
			p=0;
		}
	}
	cout<<ans;
	return 0;
}
