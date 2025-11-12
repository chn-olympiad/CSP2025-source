#include<bits/stdc++.h>
using namespace std;
long long ans,ans1;
long long t;
long long n;
long long one,two,three;
long long one1,two1,three1;
struct p{
	long long num,goods,from;
};
p all[100001];
bool is_choosed[100001];
bool is_choosed1[100001];
long long tor;
long long now;
bool for_goods(p a,p b) {
	if (a.goods!=b.goods) return a.goods>b.goods;
	else if (a.goods==b.goods) return a.num<b.num;
	return a.from<b.from;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int ii=1;ii<=t;ii++) {
		cin>>n;
		ans=0,ans1=0;
		tor=0;
		one=0,two=0,three=0;
		one1=0,two1=0,three1=0;
		now=1;
		bool shaked[4]={true,true,true,true};
//		bool shaked1[4]={true,true,true,true};
		memset(is_choosed,0,sizeof(is_choosed));
		memset(is_choosed1,0,sizeof(is_choosed));
		for (int i=0;i<n;i++) {
			for (int j=1;j<=3;j++) {
				cin>>all[(i*3)+j].goods;
				all[(i*3)+j].num=(i+1);
				all[(i*3)+j].from=j;
			}
		}
		sort(all+1,all+(3*n)+1,for_goods);
		while (tor<=n) {
		    if (shaked[all[now].from]&&is_choosed[all[now].num]==false) {
				tor++;
				is_choosed[all[now].num]=true;
				ans+=all[now].goods;
				if (all[now].from==1) one++;
				if (one==(n/2)) shaked[1]=false;
				if (all[now].from==2) two++;
				if (two==(n/2)) shaked[2]=false;
				if (all[now].from==3) three++;
				if (three==(n/2)) shaked[3]=false;
			}
			now++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}