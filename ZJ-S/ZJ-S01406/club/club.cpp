#include<bits/stdc++.h>
using namespace std;
long long a[100005][5],b[100005][5],b2[100005][5],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n,ans=0,cnt[5]={};
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(b2,0,sizeof(b2));
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>b[i][1]){
					b2[i][1]=b[i][1];
					b2[i][2]=b[i][2];
					b[i][1]=a[i][j];
					b[i][2]=j;
				}
				if(a[i][j]>b2[i][1]&&a[i][j]!=b[i][1]){
					b2[i][1]=a[i][j];
				}
			}
			cnt[b[i][2]]++;
			ans+=b[i][1];
		}
		for(long long i=1;i<=3;i++){
			long long x=0;
			if(cnt[i]>n/2){
				for(long long j=1;j<=n;j++){
					if(b[j][2]==i){
						x++;
						c[x]=b[j][1]-b2[j][1];
					}
				}
				sort(c+1,c+1+x);
				for(long long k=1;k<=x-n/2;k++){
					cnt[i]--;
				    ans-=c[k];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

