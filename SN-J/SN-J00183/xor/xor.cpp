#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005][10],vis[100005],ans=0;
int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int m=a[i],cnt=0;
		while(m) {
			b[i][cnt++]=m%2;
			m/=2;
		}
	}
	for(int z=0; z<=n; z++) {
		for(int i=1,j=i+z;j<=n; i++,j++) {
			int sum=0;
			if(i==j) {
				sum=a[i];
			} else {
				int d[10];
				for(int c=0; c<8; c++) {
					if(b[i][c]==b[i+1][c]) {
						d[c]=0;
					} else {
						d[c]=1;
					}
				}
				for(int x=i+2; x<=j; x++) {
					for(int c=0; c<8; c++) {
						if(d[c]==b[x][c]) {
							d[c]=0;
						} else {
							d[c]=1;
						}
					}
				}
				for(int c=0; c<8; c++) {
					sum=sum+d[c]*pow(2,c);
				}
			}
			if(sum==k) {
				bool f=0;
				for(int x=i; x<=j; x++) {
					if(vis[x]==1) {
						f=1;
						break;
					}
				}
				if(f==0) {
					ans++;
					
					for(int x=i; x<=j; x++) {
						vis[x]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
