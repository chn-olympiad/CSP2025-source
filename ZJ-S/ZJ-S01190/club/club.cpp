#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
#define v1 first
#define v2 second
#define IINF 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=1e5+5;
int a[N][3];
int cnt[3];
int tp[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("res.out","w",stdout);
	int t;
	sc("%d",&t);
	while(t--){
		int n;
		sc("%d",&n);
		for(int i=1; i <= n; i++){
			for(int j=0; j < 3; j++){
				sc("%d",&a[i][j]);
			}
		}
		for(int i=0;i < 3; i++)cnt[i]=0;
		for(int i=1; i <= n; i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				cnt[0]++;
				tp[i]=0;
			}
			else if(a[i][1]>=a[i][2]){
				cnt[1]++;
				tp[i]=1;
			}
			else cnt[tp[i]=2]++;
		}
		int ans=0;
		for(int i=1;i <= n; i++)ans+=a[i][tp[i]];
		if(cnt[0]>n/2){
			vector<int> v;
			for(int i=1; i <= n; i++){
				if(tp[i]==0)v.push_back(a[i][0]-max(a[i][1],a[i][2]));
			}
			sort(v.begin(),v.end());
			int loc=0;
			while(cnt[0]>n/2){
				ans-=v[loc];
				cnt[0]--;
				loc++;
			}
		}
		else if(cnt[1]>n/2){
			vector<int> v;
			for(int i=1;i  <= n; i++){
				if(tp[i]==1)v.push_back(a[i][1]-max(a[i][0],a[i][2]));
			}
			sort(v.begin(),v.end());
			int loc=0;
			while(cnt[1]>n/2){
				ans-=v[loc];
				cnt[1]--;
				loc++;
			}
		}
		else if(cnt[2]>n/2){
			vector<int> v;
			for(int i=1; i <= n; i++){
				if(tp[i]==2)v.push_back(a[i][2]-max(a[i][0],a[i][1]));
			}
			sort(v.begin(),v.end());
			int loc=0;
			while(cnt[2]>n/2){
				ans-=v[loc];
				cnt[2]--;
				loc++;
			}
		}
		pr("%d\n",ans);
	}
	return 0;
}