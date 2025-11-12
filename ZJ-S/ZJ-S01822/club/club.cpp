#include <bits/stdc++.h>
using namespace std;
int n,ans=-100;
bool flag[100006];
struct node{
	int num,id;
}a[100006],b[100006],c[100006];
node d[100005];
void dfs(int A,int B,int C,int sum,int now){
	if(A>n/2||B>n/2||C>n/2){
		return;
	}if(A+B+C>n){
		return;
	}
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(flag[now]==0){
		flag[now]=1;
		dfs(A+1,B,C,sum+a[now].num,now+1);
		flag[now]=0;	
	}
	if(flag[now]==0){
		flag[now]=1;
		dfs(A,B+1,C,sum+b[now].num,now+1);
		flag[now]=0;
	}
	if(flag[now]==0){
		flag[now]=1;
		dfs(A,B,C+1,sum+c[now].num,now+1);
		flag[now]=0;
	}
}
bool cmp(node xx,node yy){
	return xx.num>yy.num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	bool flaga=1,flagb=1;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].id=b[i].id=c[i].id=0;
			if(b[i].num!=0){
				flaga=0;
			}
			if(c[i].num!=0){
				flagb=0;
			}
		}
		if(flaga){
			ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].num;
			}
			cout<<ans<<endl;
			continue;
		}
		if(flagb){
			ans=0;
			for(int i=1;i<=n;i++){
				d[i].num=a[i].num-b[i].num;
				d[i].id=i;
			}
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[d[i].id].num;
				//cout<<a[d[i].id].num<<" ";
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=b[d[i].id].num;
				//cout<<b[d[i].id].num<<" ";
			}
			cout<<ans<<endl;
			continue;
		}
		ans=-1;
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
