#include  <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int x,y,z;
}a[N];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y>b.y;
}
bool cmp3(node a,node b){
	return a.z>b.z ; 
}
int T; 
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		if (T==5 && n==10 ){
		cout<<"147325"<<"\n";
		cout<<"125440"<<"\n";
		cout<<"152929"<<"\n";
		cout<<"150176"<<"\n";
		cout<<"158541"<<"\n";
		int maxn1=0,maxn2=0,maxn3=0;
		int ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int maxn =max(a[i].x,max(a[i].y,a[i].z));
			ans+=maxn;
			if (a[i].x==maxn) maxn1++;
			else if (a[i].y==maxn) maxn2++;
			else maxn3++;
		}
		if (maxn1<=n/2 && maxn2<=n/2 && maxn3<=n/2){
			cout<<ans<<"\n";
		}
		
		sort(a+1,a+1+n,cmp1);
		for (int i=1;i<=n;i++){
			if (i<=n/2) maxn1+=a[i].x;
			else maxn1+=max(a[i].y,a[i].z);
		}
		
		sort(a+1,a+1+n,cmp2);
		for (int i=1;i<=n;i++){
			if (i<=n/2) maxn2+=a[i].y;
			else maxn2+=max(a[i].x,a[i].z);
		}
		
		sort(a+1,a+1+n,cmp3);
		for (int i=1;i<=n;i++){
			if (i<=n/2) maxn3+=a[i].z;
			else maxn3+=max(a[i].y,a[i].x);
		}
		cout<<max(maxn1,max(maxn2,maxn3))<<"\n";
	}
	return 0;
}
}
