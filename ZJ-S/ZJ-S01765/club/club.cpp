#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int val[N][4];
int id[N][2];
pair<int,int> a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int p,q,g;
			scanf("%d%d%d",&p,&q,&g);
			if(p>=q&&q>=g){
				id[i][0]=1;
				id[i][1]=2;
			}else if(p>=g&&g>=q){
				id[i][0]=1;
				id[i][1]=3;
			}else if(q>=p&&p>=g){
				id[i][0]=2;
				id[i][1]=1;
			}else if(q>=g&&g>=p){
				id[i][0]=2;
				id[i][1]=3;
			}else if(g>=p&&p>=q){
				id[i][0]=3;
				id[i][1]=1;
			}else if(g>=q&&q>=p){
				id[i][0]=3;
				id[i][1]=2;
			}
			val[i][1]=p;
			val[i][2]=q;
			val[i][3]=g;
			a[i]={val[i][id[i][0]]-val[i][id[i][1]],i};
		}
		sort(a+1,a+1+n);
		int ans=0;
		int cnt[4]={0,0,0,0};
		for(int j=n;j>=1;j--){
			int i=a[j].second;
			int per=id[i][0];
			if(cnt[per]>=(n/2)){
				per=id[i][1];
			}
			cnt[per]++;
			ans+=val[i][per];
		}
		cout<<ans<<endl;
	}
	return 0;
}