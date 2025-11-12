#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],r,p[4],maax[100005],mid[100005],ans,dt[50005],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		p[0]=0,p[1]=0,p[2]=0,p[3]=0,ans=0;
		for(int i=1;i<=n;i++){
			a[i][0]=0;
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			maax[i]=1;
			for(int j=2;j<=3;j++){
				if(a[i][j]>a[i][maax[i]]){
					maax[i]=j;
				}
			}
			a[i][0]=maax[i],p[maax[i]]++;
			if(maax[i]==1){
				if(a[i][2]>=a[i][3]) mid[i]=2;
				else mid[i]=3;
			}else if(maax[i]==2){
				if(a[i][1]>=a[i][3]) mid[i]=1;
				else mid[i]=3;
			}else if(maax[i]==3){
				if(a[i][1]>=a[i][2]) mid[i]=1;
				else mid[i]=2;
			}
		}
		for(int i=1;i<=3;i++){
			if(p[i]>n/2) p[0]=i;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][0]];
			if(maax[i]==p[0]){
				cnt++,dt[i]=a[i][maax[i]]-a[i][mid[i]];
			}
		}
		if(p[0]){
			sort(dt+1,dt+cnt+1);
			r=0;
			while(p[p[0]]>n/2){
				r++;
				p[p[0]]--;
				ans-=dt[r];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}