#include<bits/stdc++.h>
using namespace std;
int n,t;

int cnt[5],tot;
pair<int,int>v[5];
struct node{
	int fi,fiw;
	int se,sew;
	int dw;
}a[100005],b[100005];
long long ans;


bool cmp(node a,node b){
	return a.dw>b.dw;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int aa,ab,ac;
			v[1].second=1;
			v[2].second=2;
			v[3].second=3;
			scanf("%d%d%d",&v[1].first,&v[2].first,&v[3].first);
			sort(v+1,v+1+3);
			a[i].fi=v[3].second;
			a[i].fiw=v[3].first;
			a[i].se=v[2].second;
			a[i].sew=v[2].first;
			a[i].dw=a[i].fiw-a[i].sew;
			//cout<<a[i].fi<<' '<<a[i].fiw<<' '<<a[i].se<<' '<<a[i].sew<<' '<<a[i].dw<<"\n";
		}
		//cout<<"alg st\n";
		int mp=1;
		for(int i=1;i<=n;i++){
			cnt[a[i].fi]++;
		}
		int mx=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>mx){
				mx=cnt[i];
				mp=i;
			}
		}
		for(int i=1;i<=n;i++){
			//cout<<mp<<' '<<a[i].fi<<"\n";
			if(a[i].fi==mp){
				b[++tot]=a[i];
				
			}
			else{
				ans+=a[i].fiw;
			}
		}
		sort(b+1,b+1+tot,cmp);
		for(int i=1;i<=tot;i++){
			if(i<=(n/2)){
				//cout<<"cl1\n";
				ans+=b[i].fiw;
			}
			else{
				//cout<<"cl2\n";
				ans+=b[i].sew;
			}
		}
		printf("%lld\n",ans);
		//init cnt v a b ans tot
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		v[1].first=0;
		v[1].second=0;
		v[2].first=0;
		v[2].second=0;
		v[3].first=0;
		v[3].second=0;
		for(int i=1;i<=n;i++){
			a[i].fi=0;
			a[i].fiw=0;
			a[i].se=0;
			a[i].sew=0;
			a[i].dw=0;
			b[i]=a[i];
		}
		ans=0;
		tot=0;
	}
	return 0;
}
/*
1
4
4 2 1
4 3 2
5 3 4
5 1 3
*/
