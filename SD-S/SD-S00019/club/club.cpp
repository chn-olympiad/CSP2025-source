#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
int T;
int n;
struct node{
	int x,y,z;
}a[100005];
priority_queue<pair<pi,int>,vector<pair<pi,int> >,greater<pair<pi,int> > >b[5];
int tot1,tot2,tot3;
int ans;
void init(){
	for(int i=1;i<=n;i++){
		a[i]={0,0,0};
	}
	tot1=tot2=tot3=0;
	ans=0;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				tot1++;
				b[1].push({{a[i].x-max(a[i].y,a[i].z),a[i].x},i});
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				tot2++;
				b[2].push({{a[i].y-max(a[i].x,a[i].z),a[i].y},i});
			}
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
				tot3++;
				b[3].push({{a[i].z-max(a[i].x,a[i].y),a[i].z},i});
			}
			if(tot1>n/2){
				//cout<<"!!! 1 ";
				int x=b[1].top().second;
				//cout<<x<<endl;
				b[1].pop();
				tot1--;
				if(a[x].y>=a[x].z)b[2].push({{a[x].y-a[x].z,a[x].y},x}),tot2++;
				else b[3].push({{a[x].z-a[x].y,a[x].z},x}),tot3++;
			}
			if(tot2>n/2){
				//cout<<"!!! 2 ";
				int x=b[2].top().second;
				//cout<<x<<endl;
				b[2].pop();
				tot2--;
				if(a[x].x>=a[x].z)b[1].push({{a[x].x-a[x].z,a[x].x},x}),tot1++;
				else b[3].push({{a[x].z-a[x].x,a[x].z},x}),tot3++;
			}
			if(tot3>n/2){
				//cout<<"!!! 3 ";
				int x=b[3].top().second;
				//cout<<x<<endl;
				b[3].pop();
				tot3--;
				if(a[x].x>=a[x].y)b[1].push({{a[x].x-a[x].y,a[x].x},x}),tot1++;
				else b[2].push({{a[x].y-a[x].x,a[x].y},x}),tot2++;
			}
		}
		for(int i=1;i<=3;i++){
			while(!b[i].empty()){
				//cout<<"qwq "<<i<<' '<<b[i].top().second<<endl;
				int x=b[i].top().first.second;
				ans+=x;
				b[i].pop();
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


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
