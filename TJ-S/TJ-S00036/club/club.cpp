#include<bits/stdc++.h> 
using namespace std;
int t,n;
long long ans;
int a[110000][6],b[110000];
int q[4][2]={{0,0},{3,2},{1,3},{1,2}};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int h=1;h<=t;h++){
		ans=0;
		int cnt[4]={0,0,0,0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]){
				if(a[i][1]>=a[i][3]) a[i][4]=1;
				else a[i][4]=3;
			}else if(a[i][3]>a[i][2]){
				a[i][4]=3;
			}else a[i][4]=2;
			ans+=a[i][a[i][4]];
			cnt[a[i][4]]++;
		}
		int p[10];
		p[1]=0,p[2]=n/2;
		if(cnt[1]>n/2)p[1]=1,p[2]=cnt[1];
		if(cnt[2]>n/2)p[1]=2,p[2]=cnt[2];
		if(cnt[3]>n/2)p[1]=3,p[2]=cnt[3];
		for(int i=1;i<=p[2]-n/2;i++)b[i]=110000;
		if(p[1]!=0){
			for(int i=1;i<=n;i++){
				if(a[i][4]==p[1]){
					int d=a[i][p[1]]-max(a[i][q[p[1]][0]],a[i][q[p[1]][1]]);
					if(d<b[p[2]-n/2]){
						b[p[2]-n/2]=d;
						for(int j=p[2]-n/2;j>=1;j--){
							long long g;
							if(b[j-1]>b[j]){
								g=b[j-1];
								b[j-1]=b[j];
								b[j]=g;
							}else break;
						}	
					}
								
				}
			}
			for(int i=1;i<=p[2]-n/2;i++){
				if(b[i]!=110000)ans-=b[i];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
