#include<bits/stdc++.h>
using namespace std;
struct cube{
	int p,d;
};
void swap(cube &a,cube &b){
	swap(a.p,b.p);
	swap(a.d,b.d);
}
struct node{
	cube x,y,z;
};
int t;
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin>>t;
	while(t--){
		int cube[4]={0,0,0,0};
		int n,ans=0;
		cin>>n;
		vector<node> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].x.p>>a[i].y.p>>a[i].z.p;
			a[i].x.d=0;
			a[i].y.d=1;
			a[i].z.d=2;
			while(!(a[i].x.p>=a[i].y.p&&a[i].y.p>=a[i].z.p)){
				if(a[i].x.p<a[i].y.p){
					swap(a[i].x,a[i].y);
				}
				if(a[i].y.p<a[i].z.p){
					swap(a[i].y,a[i].z);
				}
				if(a[i].x.p<a[i].z.p){
					swap(a[i].x,a[i].z);
				}
			}
		}
		for(int i=0;i<n;i++){
			if(cube[a[i].x.d]<n/2){
				ans+=a[i].x.p;
				cube[a[i].x.d]++;
			}
			else if(cube[a[i].y.d]<n/2){
				ans+=a[i].y.p;
				cube[a[i].y.d]++;
			}
			else{
				ans+=a[i].z.p;
				cube[a[i].z.d]++;
			}
		}
		cout<<ans<<endl;
	}
 } 
/*#include<bits/stdc++.h>
using namespace std;
int t;
int dp[100001][4][500001]={};
int main(){
	//freopen("cube1.in","r",stdin);
	//freopen("cube.out","w",stdout);
	cin>>t;
	while(t--){
		int n,p;
		cin>>n;
		p=n/2;
		int a[4][100001];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j][p]=max(dp[i-1][j][p],dp[i-1][j][p-a[i][j]]+a[i][j]);
			}
		}
		cout<<dp[n][1][0]+dp[n][2][0]+dp[n][3][0];
	}
	return 0;
	//999666ccf 疯了 T1 出dp wt*!@#$%^&*() T2 图论 T3T4更**d@#$%^&*(&^%$#%^&*(&^%$#@#$%^&*^%$#%^&*&^%$%^&*&^%$ 
}*/









/*
#include<bits/stdc++.h>
using namepsace std;
struct node{
	bool b;
	int x;
};
int main(){
	 int t;
	 cin>>t;
	 while(t--){
	 	int n,ans=0;
	 	cin>>n;
	 	vector<node> a(n);
	 	vector<node> b(n);
	 	vector<node> c(n);
	 	for(int i=0;i<n;i++){
	 		cin>>a[i].x>>b[i].x>>c[i].x;
		}
		sort(a.bigen(),a.end());
		sort(b.bigen(),b.end());
		sort(c.bigen(),c.end());
		for(int i=0;i<n/2;i++){
			if(!a[i].b){
				ans+=a[i].x;
				a[i].b=1;
			}
		}
		cout<<ans;
	 }
}
//a:5 5 4 2
//b:5 3 2 2
//c:4 4 1 1
//更好的贪心 
*/
