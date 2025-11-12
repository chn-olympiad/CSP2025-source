#include<bits/stdc++.h>
using namespace std;
struct mn{
	int n,t,pos;
}a[10000];
int cm(mn a,mn b){
	return a.n>b.n;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,cnt=1,sum=0,vis[10000]={0},g[3]={0},flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[cnt].n;
				a[cnt].t=i;
				a[cnt].pos=j;
				cnt++;
				if(j==2&&a[cnt].n==0&&a[cnt].n==0)flag=0;
			}
	}
	sort(a+1,a+1+n*3,cm);
	if(flag==1){
		int sum=0;
		for(int i=1;i<n/2;i++){
			sum+=a[i].n;
		}
		cout<<sum;
		return 0;
	}
	
	for(int i=1;i<=n*3;i++){
		if(vis[a[i].t]==0&&g[a[i].pos]<n/2){
			sum+=a[i].n;
			g[a[i].pos]++;
			vis[a[i].t]=1;
		}
	}
	cout<<sum<<endl;
	}
	return 0;
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
4 0 0*/
} 
