#include<bits/stdc++.h> 
using namespace std;
long long t,f1=1,f2=1,n,a,cnt1,cnt2,cnt3,ans;
struct qwe{
	long long sum,x,y,z;
};
struct node{
	long long a1,a2,a3;
}p[100005];
bool cmp1(node x,node y){
	return x.a1>y.a1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a;
				if(j==1) p[i].a1=a;
				else if(j==2) p[i].a2=a;
				else p[i].a3=a;
			}
			if(p[i].a2!=0||p[i].a3!=0) f1=0;
			if(p[i].a3!=0) f2=0;
			if(p[i].a1>=p[i].a2&&p[i].a1>=p[i].a3) cnt1++;
			else if(p[i].a2>=p[i].a1&&p[i].a2>=p[i].a3) cnt2++;
			else if(p[i].a3>=p[i].a2&&p[i].a3>=p[i].a1) cnt3++;
		}
		if(n==2){
			ans=max(p[1].a1+p[2].a2,p[1].a1+p[2].a3);
			ans=max(p[1].a2+p[2].a1,ans);
			ans=max(p[1].a2+p[2].a3,ans);
			ans=max(p[1].a3+p[2].a1,ans);
			ans=max(p[1].a3+p[2].a2,ans);
			cout<<ans<<'\n'; 
			continue;
		}
		if(f1){
			sort(p+1,p+n+1,cmp1);
			for(int i=1;i<=min(cnt1,n/2);i++){
				ans+=p[i].a1;
				p[i].a1=p[i].a2=p[i].a3=0;
			}
			cout<<ans;
			continue;
		} 
		if(f2){
			queue<qwe> q;
			for(int i=1;i<=n;i++){
				if(i==1){
					q.push({p[i].a1,1,0,0});
					q.push({p[i].a2,0,1,0});
					continue;
				}
				else{
					for(int k=1;k<=pow(2,i-1);k++){
						for(int j=1;j<=2;j++){
							qwe r=q.front();
							if(j==1){
								if(r.x<n/2) q.push({r.sum+p[i].a1,r.x+1,r.y,r.z}),ans=max(r.sum+p[i].a1,ans);
								else q.push({r.sum,r.x,r.y,r.z}),ans=max(r.sum,ans);
							}
							else{
								if(r.y<n/2) q.push({r.sum+p[i].a2,r.x,r.y+1,r.z}),ans=max(r.sum+p[i].a2,ans);
								else q.push({r.sum,r.x,r.y,r.z}),ans=max(r.sum,ans);
							}
						}
						q.pop();	
					}	
				}	
			}
			cout<<ans<<'\n';
			continue;	
		}
		queue<qwe> q;
		for(int i=1;i<=n;i++){
			if(i==1){
				q.push({p[i].a1,1,0,0});
				q.push({p[i].a2,0,1,0});
				q.push({p[i].a3,0,0,1});
				continue;
			}
			else{
				for(int k=1;k<=pow(3,i-1);k++){
					for(int j=1;j<=3;j++){
						qwe r=q.front();
						if(j==1){
							if(r.x<n/2) q.push({r.sum+p[i].a1,r.x+1,r.y,r.z}),ans=max(r.sum+p[i].a1,ans);
							else q.push({r.sum,r.x,r.y,r.z}),ans=max(r.sum,ans);
						}
						else if(j==2){
							if(r.y<n/2) q.push({r.sum+p[i].a2,r.x,r.y+1,r.z}),ans=max(r.sum+p[i].a2,ans);
							else q.push({r.sum,r.x,r.y,r.z}),ans=max(r.sum,ans);
						}
						else{
							if(r.z<n/2) q.push({r.sum+p[i].a3,r.x,r.y,r.z+1}),ans=max(r.sum+p[i].a3,ans);
							else q.push({r.sum,r.x,r.y,r.z}),ans=max(r.sum,ans);
						}
					}
					q.pop();	
				}	
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
