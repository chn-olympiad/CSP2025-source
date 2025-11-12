#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c,sadness,mx;
}t[100010];
vector<node>f[10];
int cmp(node a,node b){
	return a.sadness<b.sadness;
}
int main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++){
			f[i].clear();
		}
		long long n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			t[i].mx=max(t[i].a,max(t[i].b,t[i].c));
			t[i].sadness=max(t[i].a,max(t[i].b,t[i].c))-(t[i].a+t[i].b+t[i].c-max(t[i].a,max(t[i].b,t[i].c))-min(t[i].a,min(t[i].b,t[i].c)));
			//cout<<"sad:"<<t[i].sadness<<" ";
			if(max(t[i].a,max(t[i].b,t[i].c))==t[i].a){
				f[1].push_back(t[i]);
			}
			if(max(t[i].a,max(t[i].b,t[i].c))==t[i].b){
				f[2].push_back(t[i]);
			}
			if(max(t[i].a,max(t[i].b,t[i].c))==t[i].c){
				f[3].push_back(t[i]);
			}
			ans+=t[i].mx;
		}
		//cout<<"\n";
		for(int i=1;i<=3;i++){
			if(f[i].size()>n/2){
				sort(f[i].begin(),f[i].end(),cmp);
				int j=0;
				while(f[i].size()-j>n/2){
					//cout<<"sadness:"<<f[i][j].sadness<<"\n";
					ans-=f[i][j++].sadness;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}