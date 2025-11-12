#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c1,c2,c3;
struct w{
	int w1,w2,w3;
}a[100001];
struct d{
	int w,id;
}d1[100001],d2[100001],d3[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].w1>>a[i].w2>>a[i].w3;
			int mx=a[i].w1,fw=1;
			if(a[i].w2>mx){
				mx=a[i].w2;
				fw=2;
			}
			if(a[i].w3>mx){
				mx=a[i].w3;
				fw=3;
			}
			if(fw==1){
				d1[++c1].w=mx;
				d1[c1].id=i;
			}
			if(fw==2){
				d2[++c2].w=mx;
				d2[c2].id=i;
			}
			if(fw==3){
				d3[++c3].w=mx;
				d3[c3].id=i;
			}
			ans+=mx;
		}
		if(c1>n/2){
			priority_queue <int,vector<int>,greater<int> > q;
			for(int i=1;i<=c1;i++){
				q.push(d1[i].w-max(a[d1[i].id].w2,a[d1[i].id].w3));
			}
			for(int i=1;i<=c1-n/2;i++){
				ans-=q.top();q.pop();
			}
		}
		else if(c2>n/2){
			priority_queue <int,vector<int>,greater<int> > q;
			for(int i=1;i<=c2;i++){
				q.push(d2[i].w-max(a[d2[i].id].w1,a[d2[i].id].w3));
			}
			for(int i=1;i<=c2-n/2;i++){
				ans-=q.top();q.pop();
			}
		}
		else if(c3>n/2){
			priority_queue <int,vector<int>,greater<int> > q;
			for(int i=1;i<=c3;i++){
				q.push(d3[i].w-max(a[d3[i].id].w1,a[d3[i].id].w2));
			}
			for(int i=1;i<=c3-n/2;i++){
				ans-=q.top();q.pop();
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
