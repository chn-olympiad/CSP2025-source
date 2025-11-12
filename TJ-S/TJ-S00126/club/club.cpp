#include<bits/stdc++.h>
using namespace std;

struct node{
	int num;
	int bh;
};
int cmp(node x,node y){
	return x.num<y.num;
}
long long n,t;
int mx[4];
node a[10];
node b[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int m1=0,m2=0,m3=0;
//		int cnt;
		int ans = 0;
		int maxx = 0,maxx1 = 0,mi=0,mi1=0;
		int cnt=0,cnt1 = 0;
//		int n1 = n/2;
		cin>>a[1].num>>a[2].num>>a[3].num;
		a[1].bh = 1;
		a[2].bh = 2;
		a[3].bh = 3;
		sort(a+1,a+3+1,cmp);
		cin>>b[1].num>>b[2].num>>b[3].num;
		b[1].bh = 1;
		b[2].bh = 2;
		b[3].bh = 3;
		sort(b+1,b+3+1,cmp);
		if(b[3].bh != a[3].bh){
			ans = b[3].num+a[3].num;
		}else{
			ans = max(b[3].num+a[2].num,b[2].num+a[3].num);
		}
		cout<<ans;
//		for(int j=1;j<=n;j++){
//			cin>>m[j].b1>>m[j].b2>>m[j].b3;
//			if(maxx < m[j].b1){
//				maxx = m[j].b1;
//				cnt = 1;
//			}
//			if(maxx < m[j].b2){
//				maxx = m[j].b2;
//				cnt = 2;
//			}
//			if(maxx<m[j].b3){
//				maxx = m[j].b3;
//				cnt = 3;
//			} 
//			
//			
//		}
//		for(int j=1;j<=n;j++){
//			if(m[j].b1)
//		}
		
	}
	
	
	
	return 0;
} 
