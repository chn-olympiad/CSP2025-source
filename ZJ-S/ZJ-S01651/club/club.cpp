#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id,pos,num;
	void clear(){
		id=pos=num=0;
	}
}stu[300005];
bool vis[100005];
int cnt[5],a[15],b[15],c[15],n;
long long dfs(int now,long long num,int cna,int cnb,int cnc){
	if(now>n)return num;
	long long ans=0;
	if(cna<n/2)ans=max(ans,dfs(now+1,num+a[now],cna+1,cnb,cnc));
	if(cnb<n/2)ans=max(ans,dfs(now+1,num+b[now],cna,cnb+1,cnc));
	if(cnc<n/2)ans=max(ans,dfs(now+1,num+c[now],cna,cnb,cnc+1));
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int pos=0;
		cin >> n;
		if(n<=10){
			for(int i = 1; i <= n; i++)
				cin >> a[i] >> b[i] >> c[i];
			cout << dfs(1,0,0,0,0) << endl;
		}
		else{
			for(int i = 1; i <= n; i++){
				int a,b,c;
				cin >> a >> b >> c;
				stu[++pos]={i,1,a};
				stu[++pos]={i,2,b};
				stu[++pos]={i,3,c};
			}
			sort(stu+1,stu+pos+1,[](node a,node b){return a.num>b.num;});
			long long ans=0;
			for(int i = 1; i <= pos; i++){
				if(vis[stu[i].id])continue;
				if(cnt[stu[i].pos]>=n/2)continue;
				ans+=stu[i].num;
				vis[stu[i].id]=1;
				cnt[stu[i].pos]++;
			}
			cout << ans << '\n';
			for(int i = 1; i <= pos; i++)stu[i].clear();
			for(int i = 1; i <= n; i++)vis[i]=0;
			cnt[1]=cnt[2]=cnt[3]=0;
		}
	}
	return 0;
}
