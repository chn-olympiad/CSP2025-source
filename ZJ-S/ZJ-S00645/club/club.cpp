#include<bits/stdc++.h>
using namespace std;
struct Point{
	int id,num;
};
int T,n,maxn,cnt[4];
Point a[100005][4];
int cha[100005][4],topc[4];
bool cmp(Point a,Point b){
	return a.num>b.num;
}
bool cmp2(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		topc[1]=0;topc[2]=0;topc[3]=0;
		for (int i=1;i<=n;i++){
			cin>>a[i][1].num>>a[i][2].num>>a[i][3].num;
			sort(a[i]+1,a[i]+4,cmp);
			topc[a[i][1].id]++;
			cha[topc[a[i][1].id]][a[i][1].id]=a[i][1].num-a[i][2].num;
		}
		maxn=0;
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
		for (int i=1;i<=n;i++){
			maxn+=a[i][1].num;
			cnt[a[i][1].id]++;
		}
		for (int i=1;i<=3;i++){
			if (cnt[i]>n/2){
				sort(cha[i]+1,cha[i]+topc[i]+1,cmp2);
			}
			for (int j=1;j<=cnt[i]-n/2;j++){
				maxn-=cha[j][i];
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
/*
1 4
4 2 1
3 2 4
5 3 4
3 5 1*/

