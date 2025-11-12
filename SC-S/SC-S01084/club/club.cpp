#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a11[N],a22[N],a33[N];
int ans;
int a[N][4];
int a1,a2,a3;
int tmp[N],idx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=max(a[i][1],max(a[i][2],a[i][3]));
			a1+=a[i][1];
			a2+=a[i][2];
			a3+=a[i][3];
		}
		for(int i=1;i<=n;i++){
			tmp[++idx]=a[i][4];
		}
		sort(tmp+1,tmp+1+idx);
		for(int i=1;i<=n/2;i++){
			ans+=tmp[idx--];
		}
		for(int i=1;i<=n;i++){
			tmp[i]=0;
		}
		cout<<ans<<"\n";
		ans=0;
		idx=0;
	}
	return 0;
}