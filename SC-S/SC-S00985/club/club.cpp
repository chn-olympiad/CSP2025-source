#include<bits/stdc++.h>;
using namespace std;
struct mn{
	int s,s1,s2;
}b[100005];
int n,a[100005],t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vector<int> k[4];
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&b[i].s,&b[i].s1,&b[i].s2);
			if(b[i].s>=b[i].s1&&b[i].s>=b[i].s2){
				ans+=b[i].s;
				k[1].push_back(b[i].s-max(b[i].s1,b[i].s2)); 
			}else if(b[i].s1>=b[i].s&&b[i].s1>=b[i].s2){
				ans+=b[i].s1;
				k[2].push_back(b[i].s1-max(b[i].s2,b[i].s));
			}else{
				ans+=b[i].s2;
				k[3].push_back(b[i].s2-max(b[i].s1,b[i].s));
			}
		}
		for(int i=1;i<=3;i++){
			if(k[i].size()>n/2){
				int kl=k[i].size()-n/2;
				sort(k[i].begin(),k[i].end());
				for(int j=0;j<kl;j++){
					ans-=k[i][j];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 