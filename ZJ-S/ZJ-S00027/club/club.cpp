#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int num,id;
}a[N][4];
bool vis[N];
bool cmp(node x,node y){
	if(x.num!=y.num) return x.num>y.num;
	return x.id>y.id;
}
vector<int>ve;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+1+3,cmp);
		}
		int ans=0,sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][1].num;
			if(a[i][1].id==1) sum1++;
			if(a[i][1].id==2) sum2++;
			if(a[i][1].id==3) sum3++;
		}
		if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		ve.clear();
		if(sum1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1].id==1) ve.emplace_back(a[i][1].num-a[i][2].num);
			}
			sort(ve.begin(),ve.end());
			int num=sum1-n/2;
			for(int i=0;i<num;i++) ans-=ve[i];
		}
		if(sum2>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1].id==2) ve.emplace_back(a[i][1].num-a[i][2].num);
			}
			sort(ve.begin(),ve.end());
			int num=sum2-n/2;
			for(int i=0;i<num;i++) ans-=ve[i];
		}
		if(sum3>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1].id==3) ve.emplace_back(a[i][1].num-a[i][2].num);
			}
			sort(ve.begin(),ve.end());
			int num=sum3-n/2;
			for(int i=0;i<num;i++) ans-=ve[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}