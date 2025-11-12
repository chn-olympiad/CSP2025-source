#include <bits/stdc++.h>
using namespace std;
#define N 100010
int t,a[N],n,m;
struct ho{
	pair<int,int> aa,bb,cc;
	int ma,se,th;
	char pai;
}h[N];
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin>>t;
	while (t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>h[i].aa.first>>h[i].bb.first>>h[i].cc.first;
			h[i].ma=max(max(h[i].aa.first,h[i].bb.first),max(h[i].bb.first,h[i].cc.first));
			if (h[i].ma==h[i].aa.first){
				h[i].aa.second=1;
				h[i].pai='a';
				if (h[i].cc.first>h[i].bb.first){
					h[i].se=h[i].cc.first;
					h[i].th=h[i].bb.first;
					h[i].cc.second=2;
					h[i].bb.second=3;
				}
				else {
					h[i].se=h[i].bb.first;
					h[i].th=h[i].cc.first;
					h[i].bb.second=2;
					h[i].cc.second=3;
				}
			}
			else if (h[i].ma==h[i].bb.first){
				h[i].bb.second=1;
				h[i].pai='b';
				if (h[i].cc.first>h[i].aa.first){
					h[i].se=h[i].cc.first;
					h[i].th=h[i].aa.first;
					h[i].cc.second=2;
					h[i].aa.second=3;
				}
				else {
					h[i].se=h[i].aa.first;
					h[i].th=h[i].cc.first;
					h[i].bb.second=2;
					h[i].cc.second=3;
				}
			}
			else if (h[i].ma==h[i].cc.first){
				h[i].cc.second=1;
				h[i].pai='c';
				if (h[i].aa.first>h[i].bb.first){
					h[i].se=h[i].aa.first;
					h[i].th=h[i].bb.first;
					h[i].aa.second=2;
					h[i].bb.second=3;
				}
				else {
					h[i].se=h[i].bb.first;
					h[i].th=h[i].aa.first;
					h[i].bb.second=2;
					h[i].aa.second=3;
				}
			}
		}
		int ans1=0,ans2=0,ans_1=0,ans_2=0,ans=0;
		if (n==2){
			if (h[1].pai!=h[2].pai){
				ans=h[1].ma+h[2].ma;
			}
			else if (h[1].pai==h[2].pai){
				ans1=h[1].ma+h[2].se;
				ans2=h[2].ma+h[1].se;
				ans=max(ans1,ans2);
			}
		}
		if (n==4){
			if (h[1].pai!=h[2].pai){
				ans_1=h[1].ma+h[2].ma;
			}
			else if (h[1].pai==h[2].pai){
				ans1=h[1].ma+h[2].se;
				ans2=h[2].ma+h[1].se;
				ans_1=max(ans1,ans2);
			}
			if (h[3].pai!=h[4].pai){
				ans_2=h[3].ma+h[4].ma;
			}
			else if (h[3].pai==h[4].pai){
				ans1=h[3].ma+h[4].se;
				ans2=h[4].ma+h[3].se;
				ans_2=max(ans1,ans2);
			}
			ans=max(ans_1,ans_2);
		}
		cout<<ans<<"\n";
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
--------            	  ¡¢    |
|   ,					---- |--|--|       
| |---|					  /  |--|--|
| |---|					 /|  |--|--|
| |---|					  |     |
|  .|.				      |     |
*/
