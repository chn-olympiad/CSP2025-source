//刘睿  SN-S00081  西安铁一中滨河高级中学
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct nem{
	int pr;
	int a2;
	int a1;
};
nem road[1000010];
int m,n,k,x[11][10010],ans=0;
bool cmp(nem road1,nem road2){
	return road1.pr<road2.pr;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].a1>>road[i].a2>>road[i].pr;
	}for(int i=1;i<=k;i++){
		int price;
		cin>>price;
		for(int j=1;j<=n;j++)cin>>x[i][j];
	}sort(road+1,road+1+m,cmp);
	for(int i=1;i<=(m/2)+1;i++){
		ans+=road[i].pr;
	}cout<<ans;
	return 0;
}
