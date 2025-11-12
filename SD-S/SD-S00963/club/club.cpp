#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t;
int n;
struct node{
	ll w;
	int num; 
}a[N][5];
struct node2{
	ll sum;
	int id;
}b[N];
ll anss;
int cnt[5],ans[N];
bool cmp(node2 x,node2 y){
	return x.sum<y.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		anss=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++){
			ans[i]=0;
			b[i].sum=0;
			b[i].id=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j].w;
				a[i][j].num=j;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1].w<a[i][2].w)swap(a[i][1],a[i][2]);
			if(a[i][1].w<a[i][3].w)swap(a[i][1],a[i][3]);
			if(a[i][2].w<a[i][3].w)swap(a[i][2],a[i][3]);
//			b[i].sum=a[i][1].w-a[i][2].w;
//			b[i].id=i;
		}
//		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans[i]=1;
			cnt[a[i][1].num]++;
		}
//		cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<"\n";
		int tot=0,idnum=0,cntb=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				tot=cnt[i]-n/2;
				idnum=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1].num==idnum){
				b[++cntb].sum=a[i][1].w-a[i][2].w;
				b[cntb].id=i;
			}
		}
		sort(b+1,b+1+cntb,cmp);
//		cout<<tot<<"\n";
		for(int i=1;i<=tot;i++){
			ans[b[i].id]=2;
//			cnt[a[b[i].id][2].num]++;
		}
//		cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<"\n";
		for(int i=1;i<=n;i++){
//			cout<<ans[i]<<" ";
			anss+=a[i][ans[i]].w;
		}
//		cout<<"\n";
		cout<<anss<<"\n";
	} 
	return 0;
} 
