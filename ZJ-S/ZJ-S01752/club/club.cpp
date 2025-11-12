#include<bits/stdc++.h>
using namespace std;
int t,n,maxn[100100],maxi[100100],cnt[5];
struct data{
	int x,y,z;
}a[100100];
bool cmp(data a,data b){
	return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);
}
bool cnp(data a,data b){
	return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);
}
bool cpp(data a,data b){
	return a.z-max(a.x,a.y)<b.z-max(b.x,b.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			maxn[i]=max(a[i].x,max(a[i].y,a[i].z));
			if(maxn[i]==a[i].x){
				maxi[i]=1;
			}
			if(maxn[i]==a[i].y){
				maxi[i]=2;
			}
			if(maxn[i]==a[i].z){
				maxi[i]=3;
			}
			cnt[maxi[i]]++;
		}
		int N=max(cnt[1],max(cnt[2],cnt[3]));
		if(N<=n/2){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=maxn[i];
			}
			cout<<ans<<'\n';
		}
		else{
			int ans=0;
			if(N==cnt[1]){
				vector<data>vec;
				for(int i=1;i<=n;i++){
					if(maxi[i]==1){
						vec.push_back(a[i]);
					}
					else{
						ans+=maxn[i];
					}
				}
				sort(vec.begin(),vec.end(),cmp);
				for(int i=0;i<N-(n/2);i++){
					ans+=max(vec[i].y,vec[i].z);
				}
				for(int i=N-(n/2);i<vec.size();i++){
					ans+=vec[i].x;
				}
			}
			if(N==cnt[2]){
				vector<data>vec;
				for(int i=1;i<=n;i++){
					if(maxi[i]==2){
						vec.push_back(a[i]);
					}
					else{
						ans+=maxn[i];
					}
				}
				sort(vec.begin(),vec.end(),cnp);
				for(int i=0;i<N-(n/2);i++){
					ans+=max(vec[i].x,vec[i].z);
				}
				for(int i=N-(n/2);i<vec.size();i++){
					ans+=vec[i].y;
				}
			}
			if(N==cnt[3]){
				vector<data>vec;
				for(int i=1;i<=n;i++){
					if(maxi[i]==3){
						vec.push_back(a[i]);
					}
					else{
						ans+=maxn[i];
					}
				}
				sort(vec.begin(),vec.end(),cpp);
				for(int i=0;i<N-(n/2);i++){
					ans+=max(vec[i].x,vec[i].y);
				}
				for(int i=N-(n/2);i<vec.size();i++){
					ans+=vec[i].z;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
