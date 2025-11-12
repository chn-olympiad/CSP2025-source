#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
priority_queue<int> pq;
struct node{
	int a1;
	int b1;
	int c1;
	int xu;
}stu[N];
bool cmp(node a,node b){
	return a.a1>b.a1;
}
bool cm2(node a,node b){
	return a.b1>b.b1;
}
bool cm3(node a,node b){
	return a.c1>b.c1;
}
int vis[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0; 
		int a=0;
		int b=0;
		int c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a1>>stu[i].b1>>stu[i].c1;
			stu[i].xu=i;
		}
		int ren=n/2;
		sort(stu+1,stu+1+n,cmp);
		ans+=stu[1].a1;
		a+=1;
		vis[stu[1].xu]=1;
		sort(stu+1,stu+1+n,cm2);
		for(int i=1;i<=n;i++){
			if(!vis[stu[i].xu]){
				b+=1;
				ans+=stu[i].b1;
			}
		}
		sort(stu+1,stu+1+n,cm3);
		for(int i=1;i<=n;i++){
			if(!vis[stu[i].xu]){
				b+=1;
				ans+=stu[i].b1;
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[stu[i].xu]){
				ans+=max(stu[i].a1,max(stu[i].b1,stu[i].c1));
			}
		}
	}
	cout<<ans<<" "<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
