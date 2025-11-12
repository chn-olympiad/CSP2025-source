#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N][3],cnt[3],q1[N],q2[N],q3[N],val[N];
bool cmp(int a,int b){
	
	return val[a]<val[b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cnt[0] = cnt[1] = cnt[2] = 0;
		int n;
		cin>>n;
		long long ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				q1[++cnt[0]] = i;
				val[i] = min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				ans+=a[i][0];
			}
			else if(a[i][1]>a[i][2]){
				q2[++cnt[1]] = i;
				val[i] = min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				ans+=a[i][1];
			}
			else{
				q3[++cnt[2]] = i;
				val[i] = min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				ans+=a[i][2];
			}
		}
		if(cnt[0]>n/2){
			sort(q1+1,q1+cnt[0]+1,cmp);
			for(int i=1;i<=cnt[0]-n/2;i++){
				ans-=val[q1[i]];
			}
		}
		else if(cnt[1]>n/2){
			sort(q2+1,q2+cnt[1]+1,cmp);
			for(int i=1;i<=cnt[1]-n/2;i++){
				ans-=val[q2[i]];
			}
		}
		else if(cnt[2]>n/2){
			sort(q3+1,q3+cnt[2]+1,cmp);
			for(int i=1;i<=cnt[2]-n/2;i++){
				ans-=val[q3[i]];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
