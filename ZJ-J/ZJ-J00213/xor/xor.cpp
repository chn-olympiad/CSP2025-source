#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],ans,num,vis[maxn],b[maxn];
bool flag=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){scanf("%d",&a[i]);}
	for (int i=1;i<=n;i++){
		if (a[i]==k){
			ans++;
			flag=true;
			vis[i]=1;
			continue;
		}
		if (flag){
			num=a[i];
			flag=false;
		}
		else{num=num^a[i];}
		if (num==k) {
			flag=true;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}