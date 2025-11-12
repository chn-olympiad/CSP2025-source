#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][10],mx[100010];
struct node{
	int v,w;
}b[100010];

bool cmp(node x,node y){
	return x.v>y.v;
}

int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		int s1=0,s2=0,s3=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				mx[i]=max(mx[i],a[i][j]);
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans+=mx[i];
		cout << ans <<endl; 
	}
	return 0;
}
