#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T,n;
struct E{
	int a,b,c;
	int fa=0,fb=0,fc=0;
}a[100010];
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		int x,y,z,sum;
		x=y=z=sum=0;
		for(int i=1;i<=n;i++){
			int u=a[i].a,v=a[i].b,w=a[i].c;
			if(u>=v&&u>=w){
				x++;
				sum=sum+u;
				a[i].fa=1;
			}else if(v>=u&&v>=w){
				y++;
				sum=sum+v;
				a[i].fb=1;
			}else{
				z++;
				sum=sum+w;
				a[i].fc=1;
			}
		}
		if(x>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].fa==1){
					q.push(min(a[i].a-a[i].b,a[i].a-a[i].c));
				}
			}
			for(int i=1;i<=x-n/2;i++){
				sum-=q.top();
				q.pop();
			}
		}else if(y>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].fb==1){
					q.push(min(a[i].b-a[i].a,a[i].b-a[i].c));
				}
			}
			for(int i=1;i<=y-n/2;i++){
				sum-=q.top();
				q.pop();
			}			
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].fc==1){
					q.push(min(a[i].c-a[i].a,a[i].c-a[i].b));
				}
			}
			for(int i=1;i<=z-n/2;i++){
				sum-=q.top();
				q.pop();
			}					
		}
		cout<<sum<<endl;
		memset(a,0,sizeof(a));
		while(q.size()) q.pop();
	}
	return 0;
}
