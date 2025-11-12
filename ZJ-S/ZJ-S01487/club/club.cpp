#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
//chun tan xin
#define N 100010
long long ans=0;
int T,n,a[N][4],vis[N],f[N],s[N],t[N],fid[N],sid[N],tid[N];
typedef pair<int,int> p;
priority_queue<p,vector<p>,greater<p>>d1,d2,d3;
//first:cha
//second:id
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		n=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		memset(fid,0,sizeof(fid));
		memset(sid,0,sizeof(sid));
		memset(tid,0,sizeof(tid));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			f[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(f[i]==a[i][1])fid[i]=1;
			else if(f[i]==a[i][2])fid[i]=2;
			else if(f[i]==a[i][3])fid[i]=3;
			t[i]=min(min(a[i][1],a[i][2]),a[i][3]);
			if(t[i]==a[i][1])tid[i]=1;
			else if(t[i]==a[i][2])tid[i]=2;
			else if(t[i]==a[i][3])tid[i]=3;
			sid[i]=6-fid[i]-tid[i];
			s[i]=a[i][sid[i]];
			//deal with beginning
			if(fid[i]==1){
				if(d1.size()<n/2){
					d1.push({f[i]-s[i],i});
					ans+=f[i];
				}else{
					if(d1.top().first>f[i]-s[i]){
						vis[i]++;
						ans+=s[i];
						if(sid[i]==2){
							d2.push({s[i]-t[i],i});
						}else{
							d3.push({s[i]-t[i],i});
						}
					}
					else{
						ans+=f[i]-d1.top().first;
						int j=d1.top().second;
						d1.pop();
						d1.push({f[i]-s[i],i});
//						if(sid[j]==2){
//							if(vis[j]==0){
//								d2.push({f[j]-s[j],j});
//							}else{
//								d2.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}else{
//							if(vis[j]==0){
//								d3.push({f[j]-s[j],j});
//							}else{
//								d3.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}
						//vis[j] must be zero
						//or I can't solve this problem
						if(sid[j]==2){
							d2.push({s[j]-t[j],j});
						}else{
							d3.push({s[j]-t[j],j});
						}
					}
				}
			}
			else if(fid[i]==2){
				if(d2.size()<n/2){
					d2.push({f[i]-s[i],i});
					ans+=f[i];
				}else{
					if(d2.top().first>f[i]-s[i]){
						vis[i]++;
						ans+=s[i];
						if(sid[i]==1){
							d1.push({s[i]-t[i],i});
						}else{
							d3.push({s[i]-t[i],i});
						}
					}
					else{
						ans+=f[i]-d2.top().first;
						int j=d2.top().second;
						d2.pop();
						d2.push({f[i]-s[i],i});
//						if(sid[j]==1){
//							if(vis[j]==0){
//								d1.push({f[j]-s[j],j});
//							}else{
//								d1.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}else{
//							if(vis[j]==0){
//								d3.push({f[j]-s[j],j});
//							}else{
//								d3.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}
						if(sid[j]==1){
							d1.push({s[j]-t[j],j});
						}else{
							d3.push({s[j]-t[j],j});
						}	
					}
				}
			}
			else{
				if(d3.size()<n/2){
					d3.push({f[i]-s[i],i});
					ans+=f[i];
				}else{
					if(d3.top().first>f[i]-s[i]){
						vis[i]++;
						ans+=s[i];
						if(sid[i]==2){
							d2.push({s[i]-t[i],i});
						}else{
							d1.push({s[i]-t[i],i});
						}
					}
					else{
						ans+=f[i]-d3.top().first;
						int j=d3.top().second;
						d3.pop();
						d3.push({f[i]-s[i],i});
//						if(sid[j]==2){
//							if(vis[j]==0){
//								d2.push({f[j]-s[j],j});
//							}else{
//								d2.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}else{
//							if(vis[j]==0){
//								d1.push({f[j]-s[j],j});
//							}else{
//								d1.push({s[j]-t[j],j});
//							}
//							vis[j]++;
//						}
						if(sid[j]==2){
							d2.push({s[j]-t[j],j});
						}else{
							d1.push({s[j]-t[j],j});
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		while(!d1.empty())d1.pop();
		while(!d2.empty())d2.pop();
		while(!d3.empty())d3.pop();
	}
	return 0;
}