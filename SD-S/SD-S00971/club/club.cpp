#include<bits/stdc++.h>
using namespace std;
struct clb {
	int num,lk1,lk2,lk3;
} a[100004];
int t,n;
bool vis[100004][4];
bool like1(clb x,clb y) {
	return x.lk1>y.lk1;
}
bool like2(clb x,clb y) {
	return x.lk2>y.lk2;
}
bool like3(clb x,clb y) {
	return x.lk3>y.lk3;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].lk1>>a[i].lk2>>a[i].lk3;
			a[i].num=i;
			vis[i][0]=0;
			vis[i][1]=0;
			vis[i][2]=0;
		}
		for(int i=n; i<=n+2; i++) {
			vis[i][0]=0;
			vis[i][1]=0;
			vis[i][2]=0;
		}
		//-----------------------------------------------------------
		sort(a+1,a+n+1,like1);
		int jl1=0;
		for(int i=1; i<=n>>1; i++) {
			jl1+=a[i].lk1;
			vis[a[i].num][1]=1;
			//cout<<a[i].num<<"\n";
		}
		//cout<<jl1<<"\n";
		for(int i=1; i<=n; i++) {
			if(vis[i][1]==1)continue;
			//cout<<jl1<<"\n";//
			//cout<<a[i].lk1<<"\n";
			jl1+=max(a[i].lk2,a[i].lk3);
			//cout<<a[i].lk2<<"\n"<<a[i].lk3<<"\n";
		}
		//cout<<jl1;
		//------------------------------------------------------------
		sort(a+1,a+n+1,like2);
		int jl2=0;
		for(int i=1; i<=n>>1; i++) {
			jl2+=a[i].lk2;
			vis[a[i].num][2]=1;
			//cout<<a[i].num<<"\n";
		}
		//cout<<jl2<<"\n";
		for(int i=1; i<=n; i++) {
			if(vis[i][2]==1)continue;
			
			//cout<<jl2<<"\n";//
			jl2+=max(a[i].lk1,a[i].lk3);
		}
		//-----------------------------------------------------------
		sort(a+1,a+n+1,like3);
		int jl3=0;
		for(int i=1; i<=n>>1; i++) {
			jl3+=a[i].lk3;
			vis[a[i].num][3]=1;
			//cout<<a[i].num<<"\n";
		}
		//cout<<jl3<<"\n";
		for(int i=1; i<=n; i++) {
			if(vis[i][3]==1)continue;
			//cout<<jl3<<"\n";//
			jl3+=max(a[i].lk1,a[i].lk2);
		}
		//cout<<jl1<<"\n"<<jl2<<"\n"<<jl3<<"\n";
		cout<<max(jl1,max(jl2,jl3))<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
18
4
13
*/
