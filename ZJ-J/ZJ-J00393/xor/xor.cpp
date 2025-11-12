//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N],st[N],lst[2500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(lst,-1,sizeof(lst));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	lst[0]=0;
	for(int i=1,s=0;i<=n;i++){
		s^=a[i];
		if(a[i]==k)st[i]=i;
		else st[i]=lst[s^k]+1;
		lst[s]=i;
	}
	for(int i=1,now=0;i<=n;i++){
		if(st[i]==0)continue;
		if(st[i]>now)now=i,ans++;
	}
	cout<<ans;
	return 0;
}
