#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t;
//a[N][5],srt[N] a满意度【成员】【部门】 
struct hh{
	int aa[N];//i人满意度 
	int ct;
};
hh bm[5];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1; i<=t; i++){
		int a,b,c,mx,n,up,ans;
		ans=mx=0;
		bm[1].ct=bm[2].ct=bm[3].ct=0;
		cin >> n;
		a=b=c=n;
		up=n/2;
//		cout << a << ' ' << b << ' ' << c << ' ' << mx << ' ' << n << ' ' << up << ' ' << endl;
		for(int j=1; j<=n; j++){
			cin >> bm[1].aa[j] >> bm[2].aa[j] >> bm[3].aa[j];
		}
		for(int j=1; j<=3; j++)
			sort(bm[j].aa+1, bm[j].aa+n+1);//排序成功，从小到大 
		for(int j=n; j>=1; j--){
			if(bm[1].ct>=up) a=100004;//邪门东西 
			if(bm[2].ct>=up) b=100004;
			if(bm[3].ct>=up) c=100004;
			mx=max(bm[1].aa[a],max(bm[2].aa[b],bm[3].aa[c]));
			ans+=mx;
//			cout << mx << ' ' << bm[3].ct << endl << endl;
			if(mx==bm[1].aa[a]){
				bm[1].ct++;
				a--;
			}else if(mx==bm[2].aa[b]){
				bm[2].ct++;
				b--;
			}else if(mx==bm[3].aa[c]){
				bm[3].ct++;
				c--;
			}
//			cout << bm[2].ct << endl << endl;
		}
		cout << ans << endl;
//		cout << a << ' ' << b << ' ' << c << ' ' << mx << ' ' << n << ' ' << up << ' ' << endl << endl;
	}
	return 0;
}
//完了啊啊啊啊 