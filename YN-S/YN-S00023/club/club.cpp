#include<bits/stdc++.h>

using namespace std;
int n,sum=0,cnt[4];
struct node {
	int d[4],sd[4];
	int cmax,maxi;
} a[100001];
bool cmp1(node x,node y) {
	return x.maxi<y.maxi;
}
bool cmp2(node x,node y) {
	return x.cmax<y.cmax;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		sum=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i].d[j];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				a[i].sd[j]=a[i].d[j];
			}
			sort(a[i].sd+1,a[i].sd+4);
			for(int j=1; j<=3; j++) {
				if(a[i].d[j]==a[i].sd[3]) {
					a[i].maxi=j;
					break;
				}
			}
			sum+=a[i].sd[3];
			cnt[a[i].maxi]++;
			a[i].cmax=a[i].sd[3]-a[i].sd[2];
		}
		for(int i=1; i<=3; i++) {
			if(cnt[i]>n/2) {
				int c=cnt[i]-(n/2);
				sort(a+1,a+1+n,cmp1);
				int m=1;
				while(a[m].maxi!=i) {
					m++;
				}
				sort(a+m,a+m+cnt[i],cmp2);
				for(int j=m; j<m+c; j++) {
					sum-=a[j].cmax;
				}
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}