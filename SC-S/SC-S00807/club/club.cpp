#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,cnt[4];
struct node{
	int val,id;
};
struct person{
	node w[4];
}e[N];
bool cmp1(node a,node b){
	return a.val>b.val;
}
bool cmp2(person a,person b){
	return a.w[1].val>b.w[1].val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].w[1].val>>e[i].w[2].val>>e[i].w[3].val;
			e[i].w[1].id=1;
			e[i].w[2].id=2;
			e[i].w[3].id=3;
			sort(e[i].w+1,e[i].w+4,cmp1);
		}
		sort(e+1,e+n+1,cmp2);
		long long cnt1=0,cnt2=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[e[i].w[j].id]<n/2){
					cnt1+=e[i].w[j].val;
					cnt[e[i].w[j].id]++;
					break;
				}
			}
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=n;i>=1;i--){
			for(int j=1;j<=3;j++){
				if(cnt[e[i].w[j].id]<n/2){
					cnt2+=e[i].w[j].val;
					cnt[e[i].w[j].id]++;
					break;
				}
			}
		}
		cout<<max(cnt1,cnt2)<<endl;
	}
	
	return 0;
}