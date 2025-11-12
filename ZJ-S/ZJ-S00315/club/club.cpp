/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,t,to=0,peo[4]={},hope[maxn]={};
struct l{
	int ff,name,who;
}towards[maxn];
bool cmp1(l a,l b){
	return a.ff>b.ff;
}
long long ans=0;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			int f1,f2,f3;
			cin>>f1>>f2>>f3;
			towards[++to].ff=f1;
			towards[to].name=i;
			towards[to].who=1;
			towards[++to].ff=f2;
			towards[to].name=i;
			towards[to].who=2;
			towards[++to].ff=f3;
			towards[to].name=i;
			towards[to].who=3;
		}
		sort(towards+1,towards+1+to,cmp);
		for(int i=1;i<=to;i++){
			//cout<<peo[1]<<" "<<peo[2]<<" "<<peo[3]<<endl;
			if(hope[towards[i].name]==0&&peo[towards[i].who]<n/2){
				cout<<towards[i].name<<"  "<<towards[i].who<<endl;
				hope[towards[i].name]=1;
				ans+=towards[i].ff;
				peo[towards[i].who]++;
			}
		}
		cout<<ans<<endl;
		ans=0;
		to=0;
		peo[1]=0;
		peo[2]=0;
		peo[3]=0;
		memset(hope,0,sizeof(hope));
		
	}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,t,to=0,peo[4]={},hope[maxn]={};
struct l{
	int ff,name,who;
}towards[maxn];
bool cmp(l a,l b){
	return a.ff>b.ff;
}
struct ll{
	int f1,f2,f3;
	int al1,al2,al3;
}per[maxn];
int ans=0;
void dfs(int x,int stp,int a,int b,int c){
	if(x==n+1){
		ans=max(ans,stp);
	}
	if(a<n/2){
		dfs(x+1,stp+per[x].f1,a+1,b,c);
	}
	if(b<n/2){
		dfs(x+1,stp+per[x].f2,a,b+1,c);
	}
	if(c<n/2){
		dfs(x+1,stp+per[x].f3,a,b,c+1);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		
		cin>>n;
		if(n>=1e3){
			for(int i=1;i<=n;i++){
			int f1,f2,f3;
			cin>>f1>>f2>>f3;
			towards[++to].ff=f1;
			towards[to].name=i;
			towards[to].who=1;
			towards[++to].ff=f2;
			towards[to].name=i;
			towards[to].who=2;
			towards[++to].ff=f3;
			towards[to].name=i;
			towards[to].who=3;
		}
		sort(towards+1,towards+1+to,cmp);
		for(int i=1;i<=to;i++){
			//cout<<peo[1]<<" "<<peo[2]<<" "<<peo[3]<<endl;
			if(hope[towards[i].name]==0&&peo[towards[i].who]<n/2){
				cout<<towards[i].name<<"  "<<towards[i].who<<endl;
				hope[towards[i].name]=1;
				ans+=towards[i].ff;
				peo[towards[i].who]++;
			}
		}
		cout<<ans<<endl;
		ans=0;
		to=0;
		peo[1]=0;
		peo[2]=0;
		peo[3]=0;
		memset(hope,0,sizeof(hope));
		}
		for(int i=1;i<=n;i++){
			int f1,f2,f3;
			cin>>f1>>f2>>f3;
			per[i].f1=f1;
			per[i].f2=f2;
			per[i].f3=f3;
			
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
		
	}
}
