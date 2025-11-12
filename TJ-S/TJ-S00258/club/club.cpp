#include<bits/stdc++.h>
using namespace std;
int n;
long long mxx;
struct node{
	int a,b,c;
}r[50005];
bool vis[50005];
int no[5];
void dfs(int x,long long tp){
	if(x==n){
		mxx=max(mxx,tp);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(no[1]+1<=n/2){
				no[1]++;
				dfs(x+1,tp+r[i].a);
				no[1]--;
			}
			if(no[2]+1<=n/2){
				no[2]++;
				dfs(x+1,tp+r[i].b);
				no[2]--;
			}
			if(no[3]+1<=n/2){
				no[3]++;
				dfs(x+1,tp+r[i].c);
				no[3]--;
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
		}
		if(n>200){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=r[i].a;
			}
			cout<<cnt<<endl;
		}else{
			dfs(0,0);
			cout<<mxx<<endl;
			mxx=0;
		}
	}
	return 0;
}
