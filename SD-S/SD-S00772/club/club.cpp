#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,i;
};
struct nd{
	node num[5];
	int c;
}a[100005];
bool cmp1(node a,node b){
	return a.v>b.v;
}
bool cmp2(nd a,nd b){
	return a.c>b.c;
}
int p[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0); 
	int T;cin>>T;
	while(T--){
		memset(p,0,sizeof p);
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num[1].v>>a[i].num[2].v>>a[i].num[3].v;
			a[i].num[1].i=1;a[i].num[2].i=2;a[i].num[3].i=3;
			sort(a[i].num+1,a[i].num+4,cmp1);
			a[i].c=a[i].num[1].v-a[i].num[2].v;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(p[a[i].num[1].i]>=n/2)p[a[i].num[2].i]++,ans+=a[i].num[2].v;
			else p[a[i].num[1].i]++,ans+=a[i].num[1].v;
		}
		cout<<ans<<'\n';
	}	
	return 0;
}

