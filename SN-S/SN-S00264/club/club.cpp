#include<bits/stdc++.h>//100pts
using namespace std;
int T,n,cnt[5],ans;
struct qwq{
	int typ,val;
};
struct node{
	qwq a[5];
	int cha;
}e[100005];
inline bool cmp(node x,node y){
	return x.cha>y.cha;
}
inline bool cmp1(qwq x,qwq y){
	return x.val<y.val;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	system("fc club5.ans club.out");
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[i].a[j].val;
				e[i].a[j].typ=j;
			}
			sort(e[i].a+1,e[i].a+4,cmp1);
			e[i].cha=e[i].a[3].val-e[i].a[2].val;
		}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[e[i].a[3].typ]<n/2){
				cnt[e[i].a[3].typ]++;
				ans+=e[i].a[3].val;
			}
			else{
				if(cnt[e[i].a[2].typ]<n/2){
					cnt[e[i].a[2].typ]++;
					ans+=e[i].a[2].val;
				}
				else{
					cnt[e[i].a[1].typ]++;
					ans+=e[i].a[1].val;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
