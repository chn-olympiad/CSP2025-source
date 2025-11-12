#include<bits/stdc++.h>
using namespace std;
struct u{
	int x1,x2,x3;
}v[1000005];
int n,t,b[100005],cnt[5];
long long a[1000005][5],ans=0;
bool cmp(int c,int d){
	return a[c][v[c].x3]-a[c][v[c].x2]>a[d][v[d].x3]-a[d][v[d].x2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]<=a[i][2]&&a[i][2]<=a[i][3]){
				v[i].x1=1;
				v[i].x2=2;
				v[i].x3=3;
			}
			else if(a[i][1]<=a[i][3]&&a[i][3]<=a[i][2]){
				v[i].x1=1;
				v[i].x2=3;
				v[i].x3=2;
			}
			else  if(a[i][2]<=a[i][3]&&a[i][3]<=a[i][1]){
				v[i].x1=2;
				v[i].x2=3;
				v[i].x3=1;
			}
			else if(a[i][2]<=a[i][1]&&a[i][1]<=a[i][3]){
				v[i].x1=2;
				v[i].x2=1;
				v[i].x3=3;
			}
			else if(a[i][3]<=a[i][1]&&a[i][1]<=a[i][2]){
				v[i].x1=3;
				v[i].x2=1;
				v[i].x3=2;
			}
			else if(a[i][3]<=a[i][2]&&a[i][2]<=a[i][1]){
				v[i].x1=3;
				v[i].x2=2;
				v[i].x3=1;
			}
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[v[b[i]].x3]<n/2){
				cnt[v[b[i]].x3]++;
				ans+=a[b[i]][v[b[i]].x3];
			}
			else{
				ans+=a[b[i]][v[b[i]].x2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
