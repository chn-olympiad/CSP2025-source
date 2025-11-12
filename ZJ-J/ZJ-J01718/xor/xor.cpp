#include <bits/stdc++.h>
using namespace std;
int n,k,t,w,ma,ans,cnt,flag,a[500010],f[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		f[i]=(f[i-1]^a[i]);
		if(a[i]!=1) flag=1;
	}
	/*A*/
	if(flag==0&&k==0) {
		printf("%d",n/2);
		cout<<n/2;
		return 0;
	}
	if(flag==0&&k==1) {
		return 0;
	}
	/*B*/
	if(k==1) {
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				ans++;
		printf("%d",ans);
		return 0;
	}
	if(k==0) {
		t=1;w=1;cnt=0;
		while(t<=w&&t<=n&&w<=n) {
			if(a[w]==1) cnt++;
			if(t+1==w&&a[t]==0&&a[w]==0) {
				ans++;
				t=w+1;
			}
			else if(cnt==2) {
				ans++;
				t=w+1;
			}
			w++;
		}
		printf("%d",ans);
		return 0;
	}
	/*Other*/
	for(int i=1;i<=n;i++) {
		t=1;w=1;ans=0;
		while(t<=w&&t<=i&&w<=i) {
			if((f[w]^f[t-1])==k) {
				ans++;
				t=w+1;
			}
			w++;
		}
		t=i+1;w=i+1;
		while(t<=w&&t<=n&&w<=n) {
			if((f[w]^f[t-1])==k) {
				ans++;
				t=w+1;
			}
			w++;
		}
	}
	printf("%d",ma);
	return 0;
}
