#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int NN=1e5+5;
int n,a[NN][3],t,Fi[NN],Se[NN];
struct stu{
	int num,typ,val;
	bool operator<(const stu&X)const{
		return val<X.val;
	}
};
int cnt[3];
priority_queue<stu>pq;
priority_queue<int>bck[3];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int cae=1;cae<=t;cae++){
		while(!pq.empty())pq.pop();
		for(int j=0;j<3;j++){
			while(!bck[j].empty())bck[j].pop();
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			int fi=0,se=-1;
			for(int j=0;j<3;j++){
				if(a[i][j]>a[i][fi])fi=j;
			}
			for(int j=0;j<3;j++){
				if(j==fi)continue;
				if(se==-1)se=j;
				if(a[i][j]>a[i][se])se=j;
			}
			Fi[i]=fi,Se[i]=se;
			pq.push(stu{i,fi,a[i][fi]});
		}
//		for(int i=1;i<=n;i++)cout<<Fi[i]<<" "<<Se[i]<<'\n';
		int lim=n/2;
		ll ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		while(!pq.empty()){
			stu x=pq.top();
//			cout<<x.num<<" "<<x.typ<<" "<<x.val<<'\n';
			pq.pop();
			if(cnt[x.typ]==lim){
				int y=bck[x.typ].top();
				if(x.val+y>a[x.num][Se[x.num]]){
//					cout<<"Back "<<'\n';
					ans+=x.val+y;
					bck[x.typ].pop();
					bck[x.typ].push(a[x.num][Se[x.num]]-x.val);
				}else{
					ans+=a[x.num][Se[x.num]];
				}
			}else{
				cnt[x.typ]++;
				ans+=x.val;
				bck[x.typ].push(a[x.num][Se[x.num]]-x.val);
			}
		}
		cout<<ans<<'\n';
	} 
	

	return 0;
}
