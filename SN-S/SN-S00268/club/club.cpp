//考号:SN-S00268  姓名:强小轩  学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int t,n,a[100005][5],cnt[5];
ll ans;
vector<int> v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		int siz=(int)v.size();
		while(siz--)v.pop_back();
		for(int i=1;i<=3;i++)cnt[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
			}
			else cnt[3]++;
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		int maxx=max(max(cnt[1],cnt[2]),cnt[3]);
		if(maxx>n/2){
			int ind;
			for(int i=1;i<=3;i++){
				if(cnt[i]==maxx)ind=i;
			}
			for(int i=1;i<=n;i++){
				if(a[i][ind]>=a[i][1]&&a[i][ind]>=a[i][2]&&a[i][ind]>=a[i][3]){
					int res=0;
					if(ind==1)res=max(a[i][2],a[i][3]);
					if(ind==2)res=max(a[i][1],a[i][3]);
					if(ind==3)res=max(a[i][1],a[i][2]);
					res=a[i][ind]-res;
					v.push_back(res);
				}
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<maxx-n/2;i++){
			ans-=v[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

































