#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int T,n,ans,ans1,ans2,ans3;
struct node{
	int a1,a2,a3,a4,a5,a6;
}a[N];
bool cmp(node a,node b){
	return a.a6>b.a6;
}
signed main(){
	ioi;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].a4=a[i].a1-a[i].a2;
			a[i].a5=a[i].a1-a[i].a3;
			a[i].a6=a[i].a4+a[i].a5;
		}
		ans=0;                                                   
		ans1=0;
		ans2=0;
		ans3=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a6>0&&a[i].a4>0&&a[i].a5>0&&ans1<n/2){
				ans+=a[i].a1;
				ans1++;
			}
			else if(a[i].a4>a[i].a5&&ans3<n/2){
				ans+=a[i].a3;
				ans3++;
			} 
			else if(ans2<n/2){
				ans+=a[i].a2;
				ans2++;
			}
			else if(a[i].a3>a[i].a1&&a[i].a3<n/2){
				ans+=a[i].a3;
				ans3++;
			}
			else if(ans1<n/2){
				ans+=a[i].a1;
				ans1++;
			}
			else{
				ans+=a[i].a3;
				ans3++;
			}
		}
		cout<<ans<<endl;
	}             
	return 0;
}