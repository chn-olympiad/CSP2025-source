#include<bits/stdc++.h>
using namespace std;
struct node{
	long long bmid,myd,ygid;
	long long cbmid,cmyd,cz;
}a[100005];
long long mydgg[100005][4];
bool cmp(node a,node b){
	return a.cz==b.cz ? a.myd>b.myd : a.cz>b.cz;
}
long long t;
long long n;
void solve(){
	long long aa,bb,cc;
	for(long long i=1;i<=n;i++){
		if(mydgg[i][1]>mydgg[i][2]){
			if(mydgg[i][3]>mydgg[i][1]){
				a[i].myd=mydgg[i][3];
				a[i].bmid=3;
				a[i].cmyd=mydgg[i][1];
				a[i].cbmid=1;
			}
			else if(mydgg[i][3]<mydgg[i][2]){
				a[i].myd=mydgg[i][1];
				a[i].bmid=1;
				a[i].cmyd=mydgg[i][2];
				a[i].cbmid=2;
			}
			else{
				a[i].myd=mydgg[i][1];
				a[i].bmid=1;
				a[i].cmyd=mydgg[i][3];
				a[i].cbmid=3;
			}
		}
		else{//mydgg[i][1]<mydgg[i][2]
			if(mydgg[i][3]<mydgg[i][1]){
				a[i].myd=mydgg[i][2];
				a[i].bmid=2;
				a[i].cmyd=mydgg[i][1];
				a[i].cbmid=1;
			}
			else if(mydgg[i][3]>mydgg[i][2]){
				a[i].myd=mydgg[i][3];
				a[i].bmid=3;
				a[i].cmyd=mydgg[i][2];
				a[i].cbmid=2;
			}
			else{
				a[i].myd=mydgg[i][2];
				a[i].bmid=2;
				a[i].cmyd=mydgg[i][3];
				a[i].cbmid=3;
			}
		}
		a[i].cz=a[i].myd-a[i].cmyd;
	}
	long long ans=0;
	long long bmrs[4]={0,0,0,0};
	sort(a+1,a+n+1,cmp); 
	for(long long i=1;i<=n;i++){
		if(bmrs[a[i].bmid]==n/2){
			ans+=a[i].cmyd;
			bmrs[a[i].cbmid]++;
		}
		else{
			ans+=a[i].myd;
			bmrs[a[i].bmid]++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cin>>t;; 
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>mydgg[i][1]>>mydgg[i][2]>>mydgg[i][3];
			a[i].ygid=i;
		}
		solve();
	}
	return 0;
}

