#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int k=1;
const int N=1e5+10;	
int r=0;
int f[4];
int s[4];
int dp[N][4];
struct Node{
	int p[4];
}a[N];
bool cmp1(Node x,Node y){
	return x.p[1]>y.p[1];
}
bool cmp2(Node x,Node y){
	return x.p[1]-x.p[2]>y.p[1]-y.p[2];
}
bool cmp(Node x,Node y){
	return min(x.p[1]-x.p[2],x.p[1]-x.p[3])>min(y.p[1]-y.p[2],y.p[1]-y.p[3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(s,0,sizeof s);
		memset(f,0,sizeof f);
		r=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].p[j];
				f[j]=max(f[j],a[i].p[j]);
			}
		}
		if(!f[2]&&!f[3]){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				r+=a[i].p[1];
			}
			cout<<r<<"\n";
			continue;
		}
		if(!f[3]){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(s[1]<n/2||s[2]>=n/2){
					r+=a[i].p[1];
					s[1]++;
				}else{
					r+=a[i].p[2];
					s[2]++;
				}
			}
			cout<<r<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[1]<n/2&&(a[i].p[1]>a[i].p[2]&&a[i].p[1]>a[i].p[3]||s[2]>=n/2&&a[i].p[1]>a[i].p[3]||s[3]>=n/2&&a[i].p[1]>a[i].p[2])){
				s[1]++;
				r+=a[i].p[1];
			}else if(s[2]<n/2&&(a[i].p[2]>a[i].p[3]&&a[i].p[2]>a[i].p[1]||s[1]>=n/2&&a[i].p[2]>a[i].p[3]||s[3]>=n/2&&a[i].p[2]>a[i].p[1])){
				s[2]++;
				r+=a[i].p[2];
			}else{
				s[3]++;
				r+=a[i].p[3];
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}
