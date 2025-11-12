/*
孩子们不好我 T1 想不出来
高傲战绩 1h48min 才过大样例 
气死我累，正解想到了拿去骗C性质部分分啦，我真棒
现在才发现当时的 idea 似乎可能好像挺正确的（？ 
气煞我。 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int T,n,cnt1,cnt2,cnt3,ans,c[N];
struct NODE{
	int x,y,z,d,c;
}a[N];
bool cmp(NODE a1,NODE a2){
	return a1.d<a2.d;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int tot=0,res=0;
		cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z){
				a[i].c=1,cnt1++;
				a[i].d=a[i].x-max(a[i].y,a[i].z);
				tot+=a[i].x;
			}else if(a[i].y>=a[i].x && a[i].y>=a[i].z){
				a[i].c=2,cnt2++;
				a[i].d=a[i].y-max(a[i].x,a[i].z);
				tot+=a[i].y;
			}else{
				a[i].c=3,cnt3++;
				a[i].d=a[i].z-max(a[i].x,a[i].y);
				tot+=a[i].z;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<tot<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if(cnt1>n/2){
			res=tot;
			for(int i=1;i<=n;i++){
				if(a[i].c==1 && cnt1>n/2){
					res-=a[i].d;
					cnt1--;
				}
			}
		}else if(cnt2>n/2){
			res=tot;
			for(int i=1;i<=n;i++){
				if(a[i].c==2 && cnt2>n/2){
					res-=a[i].d;
					cnt2--;
				}
			}
		}else if(cnt3>n/2){
			res=tot;
			for(int i=1;i<=n;i++){
				if(a[i].c==3 && cnt3>n/2){
					res-=a[i].d;
					cnt3--;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
