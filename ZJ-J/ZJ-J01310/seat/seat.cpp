#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=114514;

struct qwq {
	int id,score;
} a[N];

bool cmp(qwq x,qwq y) {
	return x.score>y.score;
}

int n,m;

signed main() {
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
//			cout<<a[i*m+j-m].id<<' '<<endl;
			if(i%2) {
				if(a[i*m-m+j].id==1) {
					cout<<i<<' '<<j;
					return 0;
				}
			} else {
				if(a[i*m+j-m].id==1) {
					cout<<i<<' '<<m-j+1;
					return 0;
				}
			}
		}
	}
}
//Engfish awa
//8:38 T1 ac
//9:12 T2 ac
//luogu uid = 1300065?
//by binary_carrots

//I love CCF!

//wo yao shang mi huo xing wei da shang!!!

//Brute_Force AK IOI!!!

//%%%

//9:20 I feel a bit dead.
//#Shang4Shan3Ruo6shui4

//9:27 QwQ

//What's up

//10:22 T2 20+20=40pts

//10:38 I have eaten all my chocolate!!! [cry][cry][cry]

// feng chui mai lang,dao hua xiang.
// hei tu di yang yu zhe zan de dei niang.

//11:00 I have drunk all my water

//11:42 T3 50+30=80pts


//100+100+40+80=320pts
//Don't give up hope.

//binary_carrot(myself) %%%
//__Segment__ %%%
//jkk2011 %%%
//ljh_QAQ/ljh_QWQ %%%
//cookiebus %%%
//Clv_Csy(Csy_Clv) %%%
//Brute_Force %%%
//kkksc_03 %%%
//chen_zhe %%%
//dzd %%%
//CCF %%%

