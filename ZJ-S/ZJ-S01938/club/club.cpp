#include<bits/stdc++.h>
using namespace std;
int a[4][100001],vis[100001];
int ls[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i])
				cnt[1]++,ans+=a[1][i];
			else if(a[2][i]>a[3][i])
				cnt[2]++,ans+=a[2][i];
			else
				cnt[3]++,ans+=a[3][i];	
		}
		int flag=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2)
				flag=i;
		}
		//cout<<flag<<endl;
		if(flag==0){
			cout<<ans<<endl;
			continue;
		}
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i]&&flag==1)
				ls[++cntt]=a[1][i]-max(a[2][i],a[3][i]);
			else if(a[2][i]>a[1][i]&&a[2][i]>a[3][i]&&flag==2)
				ls[++cntt]=a[2][i]-max(a[1][i],a[3][i]);
			else if(a[3][i]>a[2][i]&&a[3][i]>a[1][i]&&flag==3)
				ls[++cntt]=a[3][i]-max(a[1][i],a[2][i]);
		}
		sort(ls+1,ls+cntt+1);
		for(int i=1;i<=cnt[flag]-n/2;i++)
			ans=ans-ls[i];
		cout<<ans<<endl;
	}
	return 0;
}
