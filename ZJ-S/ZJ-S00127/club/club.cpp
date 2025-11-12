#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int vis[5];
int ans;
struct peo{
	int num[5];
	int Max;
	int cha;
	int p;
}people[100005];
bool cmp(peo a,peo b){
	return a.cha>b.cha;
}
bool judge(int i,int j){
	if(people[i].num[j]>=people[i].num[(j)%3+1]&&people[i].num[(j+1)%3+1]>=people[i].num[j])return true;
	if(people[i].num[j]<=people[i].num[(j)%3+1]&&people[i].num[(j+1)%3+1]<=people[i].num[j])return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			int Max=0;
			int Min=0x3f3f3f3f;
			int pre;
			for(int j=1;j<=3;j++){
				cin>>people[i].num[j];
				if(people[i].num[j]>Max){
					Max=people[i].num[j];
					pre=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(judge(i,j))Min=people[i].num[j];
			}
			people[i].Max=Max;
			people[i].cha=Max-Min;
			people[i].p=pre;
		}
		sort(people+1,people+1+n,cmp);
		for(int m=1;m<=n;m++){
			if(vis[people[m].p]+1<=n/2){
				ans+=people[m].Max;
				vis[people[m].p]++;
			}
			else{
				for(int i=m;i<=n;i++){
					int Max=0;
					int Min=0x3f3f3f3f;
					int pre=0;
					people[i].Max=max(people[i].num[(people[m].p)%3+1],people[i].num[(people[m].p+1)%3+1]);
					Min=min(people[i].num[(people[m].p)%3+1],people[i].num[(people[m].p+1)%3+1]);
					people[i].cha=people[i].Max-Min;
					if(people[i].num[(people[m].p)%3+1]>people[i].num[(people[m].p+1)%3+1]){
						pre=(people[m].p)%3+1;
					}
					else pre=(people[m].p+1)%3+1;
					people[i].p=pre;
			 	}
				sort(people+1+m,people+1+n,cmp);
				cout<<people[n].Max<<endl;
				m--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
