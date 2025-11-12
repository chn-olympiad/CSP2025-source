#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,pos,ans,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]==k)ans++;
	pos=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k)pos=i+1;
		else{
			int temp=a[i];
			for(int j=i-1;j>=pos;j--){
				temp=(temp^a[j]);
				if(temp==k){
					ans++;
					pos=i+1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
