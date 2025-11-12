#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;int T,n;
struct node{int x,y,z,sum,ma;}a[N];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].sum=max(a[i].x,max(a[i].y,a[i].z));
			a[i].ma=a[i].sum;
			if(a[i].x==a[i].sum) a[i].sum-=max(a[i].y,a[i].z);
			else if(a[i].y==a[i].sum) a[i].sum-=max(a[i].x,a[i].z);
			else if(a[i].z==a[i].sum) a[i].sum-=max(a[i].y,a[i].x);
		}sort(a+1,a+1+n,cmp);
		int ans[n/2+2];
		long long answer=0;
		for(int i=1;i<=n/2+2;i++)ans[i]=0;
		for(int i=1;i<=n;i++){
			if(a[i].ma==a[i].x){
				if(ans[1]<n/2){
					ans[1]++;answer+=a[i].x;
				}
				else{
					if(a[i].z>a[i].y&&ans[3]<n/2){
						ans[3]++;answer+=a[i].z;
					}
					else{
						ans[2]++;answer+=a[i].y;
					}
				}
			}
			else if(a[i].ma==a[i].y){
				if(ans[2]<n/2){
					ans[2]++;answer+=a[i].y;
				}
				else{
					if(a[i].z>a[i].x&&ans[3]<n/2){
						ans[3]++;answer+=a[i].z;
					}
					else{
						ans[1]++;answer+=a[i].x;
					}
				}
			}
			else if(a[i].ma==a[i].z){
				if(ans[3]<n/2){
					ans[3]++;answer+=a[i].z;
				}
				else{
					if(a[i].y>a[i].x&&ans[2]<n/2){
						ans[2]++;answer+=a[i].y;
					}
					else{
						ans[1]++;answer+=a[i].x;
					}
				}
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
