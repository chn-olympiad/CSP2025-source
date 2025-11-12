#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001][3],t[3];
struct node{
	int mxval,midval,mnval,pos;
	bool operator< (const node nd) const{
		return mxval-midval<nd.mxval-nd.midval;
	}
}nd[100001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(nd,0,sizeof nd);
		cin>>n;
		memset(a,0,sizeof a);
		memset(t,0,sizeof t);
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			nd[i].mxval=max(a[i][0],max(a[i][1],a[i][2]));
			nd[i].mnval=min(a[i][0],min(a[i][1],a[i][2]));
			nd[i].midval=a[i][0]+a[i][1]+a[i][2]-nd[i].mnval-nd[i].mxval;
			nd[i].pos=i;
		}
		int ans=0;
		sort(nd,nd+n);
		vector<int> vec[3];
		for(int i=0;i<n;i++){
			ans+=nd[i].mxval;
			if(nd[i].mxval==a[nd[i].pos][0]&&nd[i].mxval!=a[nd[i].pos][1]&&nd[i].mxval!=a[nd[i].pos][2]){
				t[0]++;
				vec[0].push_back(i);
			}
			else if(nd[i].mxval==a[nd[i].pos][1]&&nd[i].mxval!=a[nd[i].pos][0]&&nd[i].mxval!=a[nd[i].pos][2]){
				t[1]++;
				vec[1].push_back(i);
			}
			else if(nd[i].mxval==a[nd[i].pos][2]&&nd[i].mxval!=a[nd[i].pos][1]&&nd[i].mxval!=a[nd[i].pos][0]){
				t[2]++;
				vec[2].push_back(i);
			}
			else if(nd[i].mxval==a[nd[i].pos][0]&&nd[i].mxval==a[nd[i].pos][1]&&nd[i].mxval!=a[nd[i].pos][2]){
				if(t[0]<t[1]){
					t[0]++;
					vec[0].push_back(i);
				}
				else{
					t[1]++;
					vec[1].push_back(i);
				}
			}
			else if(nd[i].mxval==a[nd[i].pos][0]&&nd[i].mxval!=a[nd[i].pos][1]&&nd[i].mxval==a[nd[i].pos][2]){
				if(t[0]<t[2]){
					t[0]++;
					vec[0].push_back(i);
				}
				else{
					t[2]++;
					vec[2].push_back(i);
				}
			}
			else if(nd[i].mxval!=a[nd[i].pos][0]&&nd[i].mxval==a[nd[i].pos][1]&&nd[i].mxval==a[nd[i].pos][2]){
				if(t[2]<t[1]){
					t[2]++;
					vec[2].push_back(i);
				}
				else{
					t[1]++;
					vec[1].push_back(i);
				}
			}
			else{
				if(t[0]==min(t[0],min(t[1],t[2]))){
					t[0]++;
					vec[0].push_back(i);
				}
				else if(t[1]==min(t[0],min(t[1],t[2]))){
					t[1]++;
					vec[1].push_back(i);
				}
				else{
					t[2]++;
					vec[2].push_back(i);
				}
			}
		}
		if(t[0]>n/2){
			int i=0;
			while(t[0]>n/2){
				t[0]--;
				int x=nd[vec[0][i]].midval;
				ans-=nd[vec[0][i]].mxval;
				ans+=x;
				i++;
			}
		}
		if(t[1]>n/2){
			int i=0;
			while(t[1]>n/2){
				t[1]--;
				int x=nd[vec[1][i]].midval;
				ans-=nd[vec[1][i]].mxval;
				ans+=x;
				i++;
			}
		}
		if(t[2]>n/2){
			int i=0;
			while(t[2]>n/2){
				t[2]--;
				int x=nd[vec[2][i]].midval;
				ans-=nd[vec[2][i]].mxval;
				ans+=x;
				i++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//100pts