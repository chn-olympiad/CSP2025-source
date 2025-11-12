#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct P{
	int b[5];
}a[100005];
int n;
ll ans1,ans2;
int tmp1[5],tmp2[5];
int t;
int cnt[5]; 
bool cmp1(P x,P y){
	for(int i=1;i<=3;i++){
		tmp1[i]=x.b[i];
		tmp2[i]=y.b[i];
	}
	sort(tmp1+1,tmp1+3+1);
	sort(tmp2+1,tmp2+3+1);
	reverse(tmp1+1,tmp1+3+1);
	reverse(tmp2+1,tmp2+3+1);
	tmp1[4]=tmp2[4]=0;
	for(int i=1;i<=3;i++){
		if(tmp1[i]-tmp1[i+1]>tmp2[i]-tmp2[i+1]){
			return 1;
		}
		if(tmp1[i]-tmp1[i+1]<tmp2[i]-tmp2[i+2]){
			return 0; 
		}
	}
	return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans1=0;
		cin>>n;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].b[j];
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			for(int k=1;k<=3;k++){
				int mxn=1,mx=-1;
				for(int j=1;j<=3;j++){
					if(a[i].b[j]>mx){
						mxn=j;
						mx=a[i].b[j];
					}
				}
				if(cnt[mxn]<(n/2)){
					ans1+=mx;
					cnt[mxn]++;
					break;
				}
				else{
					a[i].b[mxn]=-1;
				}
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
} 