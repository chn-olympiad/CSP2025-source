#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,sum;
struct node{
	int a1,a2,a3,maxx,maxid,minn,minid,cmax,cmaxid;
}a[N];
void dfs(int ans,int pos,int res1,int res2,int res3){
	if(pos==n){
		sum=max(sum,ans);
		return;
	}if(res1<n/2)dfs(ans+a[pos+1].a1,pos+1,res1+1,res2,res3);
	if(res2<n/2)dfs(ans+a[pos+1].a2,pos+1,res1,res2+1,res3);
	if(res3<n/2)dfs(ans+a[pos+1].a3,pos+1,res1,res2,res3+1);
}bool cmp(node b,node c){
	return b.a1>c.a1;
}
void solve(){
	cin>>n;
	int max_2=0,max_3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		max_2=max(max_2,a[i].a2);
		max_3=max(max_3,a[i].a3);
	}
	set<int>cnt[5];
	if(n>15){
		if(max_2==0&&max_3==0){
			sort(a+1,a+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++)cnt+=a[i].a1;
			cout<<cnt<<endl;
		}else{
		for(int i=1;i<=n;i++){
			a[i].maxx=a[i].a1,a[i].maxid=1;
			if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)a[i].maxx=a[i].a2,a[i].maxid=2;
			if(a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2)a[i].maxx=a[i].a3,a[i].maxid=3;
			//cerr<<111;
			a[i].minn=a[i].a1,a[i].minid=1;
			if(a[i].a2<a[i].a1&&a[i].a2<=a[i].a3)a[i].minn=a[i].a2,a[i].minid=2;
			if(a[i].a3<a[i].a1&&a[i].a3<a[i].a2)a[i].minn=a[i].a3,a[i].minid=3;
			if((a[i].maxid==1&&a[i].minid==2)||(a[i].maxid==2&&a[i].minid==1))a[i].cmax=a[i].a3,a[i].cmaxid=3;
			if((a[i].maxid==1&&a[i].minid==3)||(a[i].maxid==3&&a[i].minid==1))a[i].cmax=a[i].a2,a[i].cmaxid=2;
			if((a[i].maxid==3&&a[i].minid==2)||(a[i].maxid==2&&a[i].minid==3))a[i].cmax=a[i].a1,a[i].cmaxid=1;
			//cerr<<222<<endl;
			cerr<<a[i].maxid<<" "<<a[i].maxx<<" "<<a[i].cmaxid<<" "<<a[i].cmax<<" "<<a[i].minid<<" "<<a[i].minn<<endl;
			if(cnt[a[i].maxid].size()==n/2){
				int f=*cnt[a[i].maxid].begin();
				int l1=a[f].cmax+a[i].maxx,l2=a[i].cmax+a[f].maxx,l3=a[i].minn+a[f].maxx,l4=a[f].minn+a[i].maxx;
				if(a[f].cmax+a[i].maxx>a[i].cmax+a[f].maxx){
					cnt[a[f].cmaxid].insert(f);
					cnt[a[i].maxid].erase(f);
					cnt[a[i].maxid].insert(i);
				}else{
				
					cnt[a[i].cmaxid].insert(i);
				}
			}else{
				cnt[a[i].maxid].insert(i);
			}
		}int ans=0;
		for(int i:cnt[1])ans+=a[i].a1;
		for(int i:cnt[2])ans+=a[i].a2;
		for(int i:cnt[3])ans+=a[i].a3;
		cout<<ans<<endl;
		}
		
	}else{
		sum=0;
		dfs(0,0,0,0,0);
		cout<<sum<<endl;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
