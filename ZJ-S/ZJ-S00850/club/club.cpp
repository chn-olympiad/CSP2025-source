#include <bits/stdc++.h>
using namespace std;
int T,n,a[5],s[5];
vector<int> b[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		//init
		for(int j=1;j<=3;j++)
			b[j].clear(),s[j]=0;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			int mx=max(a[1],a[2]);
			int mx2=min(a[1],a[2]);
			if(a[3]>mx)mx2=mx,mx=a[3];
			else if(a[3]>mx2)mx2=a[3];
			ans+=mx;
			for(int j=1;j<=3;j++)
			if(a[j]==mx){
				s[j]++;
				b[j].push_back(mx-mx2);//<
				break;
			}
		}
		int id=0;
		for(int j=1;j<=3;j++)
			if(s[j]>n/2){id=j;break;}
		if(id){
			sort(b[id].begin(),b[id].end());
			for(int i=0;i<s[id]-n/2;i++)ans-=b[id][i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
