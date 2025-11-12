#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,cnt[4],a[4];
int f1[100005];
int f2[100005];
int f3[100005];
void work(){
	cin>>n;
	for (int i=1;i<=3;i++) cnt[i]=0;
	int sum=0;
	for (int i=1;i<=n;i++){
		int mx=-1,mx2=-1;
		for (int j=1;j<=3;j++){
			scanf("%lld",&a[j]);
			mx=max(mx,a[j]);
		}
		bool ok=0;
		for (int j=1;j<=3;j++){
			if (!ok && a[j]==mx){
				ok=1;
				continue;
			}
			mx2=max(mx2,a[j]);
		}
		int x=mx-mx2;
		for (int j=1;j<=3;j++){
			if (a[j]==mx){
				cnt[j]++;
				if (j==1) f1[cnt[j]]=x;
				if (j==2) f2[cnt[j]]=x;
				if (j==3) f3[cnt[j]]=x;
				break;
			}
		}
		sum+=mx;
	}
	if (cnt[1]>n/2){
		sort(f1+1,f1+1+cnt[1]);
		for (int i=1;i<=cnt[1]-n/2;i++) sum-=f1[i];
	}
	if (cnt[2]>n/2){
		sort(f2+1,f2+1+cnt[2]);
		for (int i=1;i<=cnt[2]-n/2;i++) sum-=f2[i];
	}
	if (cnt[3]>n/2){
		sort(f3+1,f3+1+cnt[3]);
		for (int i=1;i<=cnt[3]-n/2;i++) sum-=f3[i];
	}
	cout<<sum<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while (t--) work();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
