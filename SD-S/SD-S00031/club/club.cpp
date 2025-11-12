#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int am;
	int bm;
	int cm;
}a[100005];
int T;
int n;
long long ans;
bool y;
void dfs(int t,long long now,int aa,int bb,int cc){
	if(t>n){
		ans=max(ans,now);
		return;
	}
	if(aa<n/2){
		dfs(t+1,now+a[t].am,aa+1,bb,cc);
	}
	if(bb<n/2){
		dfs(t+1,now+a[t].bm,aa,bb+1,cc);
	}
	if(cc<n/2){
		dfs(t+1,now+a[t].cm,aa,bb,cc+1);
	}
}
bool cmp(node x,node y){
	//cerr<<x.am<<" "<<y.am<<endl;
	return x.am>y.am;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		y=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].am>>a[i].bm>>a[i].cm;
			if(a[i].bm!=0||a[i].cm!=0){
				y=0;
			}
		}
		if(y){
			//cerr<<"y"<<endl;
			/*for(int i=1;i<=n/2;i++){
				cerr<<a[i].am<<endl;
			}*/
			sort(a+1,a+n+1,cmp);
			//cerr<<"t"<<endl;
			for(int i=1;i<=n/2;i++){
				//cerr<<a[i].am<<endl;
				ans+=a[i].am;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
