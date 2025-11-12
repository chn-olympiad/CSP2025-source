#include<bits/stdc++.h>
using namespace std;
short int t;
struct node{
	int num,id;
}tem[4];
int n,d[4];
long long ans;
priority_queue<int,vector<int>,less<int> > m1,m2,m3;
bool cmp(node p,node q){
	return p.num>q.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d",&t);
	for(int o=1;o<=t;o++){
		scanf("%d",&n);
		ans=0;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			tem[1].id=1;
			tem[2].id=2;
			tem[3].id=3;
			scanf("%d%d%d",&tem[1].num,&tem[2].num,&tem[3].num);
			//cin>>tem[1].num>>tem[2].num>>tem[3].num;
			sort(tem+1,tem+4,cmp);
			if(tem[1].id==1){
				d[1]++;
				m1.push(tem[2].num-tem[1].num);
			}
			else if(tem[1].id==2){
				d[2]++;
				m2.push(tem[2].num-tem[1].num);
			}
			else{
				d[3]++;
				m3.push(tem[2].num-tem[1].num);
			}
			ans+=(long long)tem[1].num;
		}
		if(d[1]>n/2){
			for(int i=n/2+1;i<=d[1];i++){
				ans+=(long long)m1.top();
				m1.pop();
			}
			cout<<ans<<"\n";
		}
		else if(d[2]>n/2){
			for(int i=n/2+1;i<=d[2];i++){
				ans+=(long long)m2.top();
				m2.pop();
			}
			cout<<ans<<"\n";
		}
		else{
			for(int i=n/2+1;i<=d[3];i++){
				ans+=(long long)m3.top();
				m3.pop();
			}
			cout<<ans<<"\n";
		}
		while(!m1.empty()) m1.pop();
		while(!m2.empty()) m2.pop();
		while(!m3.empty()) m3.pop();
	}
	
	return 0;
} 
