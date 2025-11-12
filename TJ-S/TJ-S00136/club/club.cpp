#include<bits/stdc++.h>
using namespace std;
long long a[500005][3];
struct aaa{
	long long z;
	long long x;
	long long l;
	long long m;
};
long long n;
bool cmp(aaa x,aaa y){
	if(x.z==y.z)return x.l>y.l;
	else return x.z<y.z;
}
int dfs(int i,int ca,int cb,int cc,long long an){
	if(i==n+1){
		return an;
	}
	int ans=0;
	if(ca<n/2)ans=max(ans,dfs(i+1,ca+1,cb,cc,an+a[i][0]));
	if(cb<n/2)ans=max(ans,dfs(i+1,ca,cb+1,cc,an+a[i][1]));
	if(cc<n/2)ans=max(ans,dfs(i+1,ca,cb,cc+1,an+a[i][2]));
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long cc[5]={0},ans=0;
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n<=10){
			printf("%lld\n",dfs(1,0,0,0,0));
			continue;
		}
		for(int i=1;i<=n;i++){
			aaa ct[5];
			for(int k=0;k<3;k++){
				ct[k].z=0;
				ct[k].x=k;
				ct[k].l=a[i][k];
				ct[k].m=0;
			}
			for(int j=i+1;j<=n;j++){
				for(int k=0;k<3;k++){
					if(a[j][k]>a[i][k])ct[k].z++;
					ct[k].m=max(ct[k].m,a[j][k]);
				}
			}
			for(int k=0;k<3;k++){
				if(cc[k]+1>=n/2)ct[k].l-=ct[k].m;
				//printf("%d ",ct[k].m);
			}
			sort(ct+0,ct+3,cmp);
			for(int j=0;j<3;j++){
				if(cc[ct[j].x]<n/2){
					ans+=ct[j].l;
					cc[ct[j].x]++;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
