#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005][4],sum;
vector<pair<int,int> >maxf[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		while(maxf[1].size())maxf[1].pop_back();
		while(maxf[2].size())maxf[2].pop_back();
		while(maxf[3].size())maxf[3].pop_back();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int p=max(a[i][1],max(a[i][2],a[i][3]));
			sum+=p;
			if(p==a[i][1])maxf[1].push_back(make_pair(a[i][1]-max(a[i][2],a[i][3]),i));
			else if(p==a[i][2])maxf[2].push_back(make_pair(a[i][2]-max(a[i][2],a[i][3]),i));
			else maxf[3].push_back(make_pair(a[i][3]-max(a[i][2],a[i][1]),i));
		}
		int ll=maxf[1].size(),jj=maxf[2].size(),kk=maxf[3].size();
		if(ll>n/2){
			sort(maxf[1].begin(),maxf[1].end());
			for(int i=0;i<maxf[1].size()-n/2;i++){
				int x=maxf[1][i].second;
				sum=sum-a[x][1];
				sum=sum+max(a[x][2],a[x][3]);
			}
		}
		else if(jj>n/2){
			sort(maxf[2].begin(),maxf[2].end());
			for(int i=0;i<maxf[2].size()-n/2;i++){
				int x=maxf[2][i].second;
				sum=sum-a[x][2];
				sum=sum+max(a[x][1],a[x][3]);
			}
		}
		else if(kk>n/2){
			sort(maxf[3].begin(),maxf[3].end());
			for(int i=0;i<maxf[3].size()-n/2;i++){
				int x=maxf[3][i].second;
				sum=sum-a[x][3];
				sum=sum+max(a[x][1],a[x][2]);
			}
		}
		cout<<sum<<endl;
	}
}