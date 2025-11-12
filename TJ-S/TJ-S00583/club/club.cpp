#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct man{
	int s1,s2,s3;
	int now;
};
bool cmp(man x,man y){
	return x.s2-x.s1>y.s2-y.s1;
}
bool cmp2(man x,man y){
	return x.s3-x.s1>y.s3-y.s1;
}
bool cmp3(man x,man y){
	return max(x.s2-x.s1,x.s3-x.s1) > max(y.s2-y.s1,y.s3-y.s1); 
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		man a[n+5];
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
			a[i].now = 1;
			ans += a[i].s1;
		}
		int cnt1 = n,cnt2 = 0,cnt3 = 0;
		sort(a+1,a+n+1,cmp3);
		int f = 1;
		bool flag = false;
		while(cnt2 < n/2&&cnt3 < n/2){
			if(a[f].s2-a[f].s1>=a[f].s3-a[f].s1){
				if(a[f].s2 < a[f].s1&&cnt1 <= n/2){ 
					flag = true;
					break;
				}
				cnt1--;
				cnt2++;
				ans += (a[f].s2-a[f].s1);
				a[f].now = 2;
			}else{
				if(a[f].s3 < a[f].s1&&cnt1 <= n/2){
					flag = true;
					break;
				}
				cnt1--;
				cnt3++;
				ans += (a[f].s3-a[f].s1);
				a[f].now = 3;
			}
			f++;
		} 
		if(!flag){
			f = 1;
			if(cnt2 < n/2){
				sort(a+1,a+n+1,cmp);
				while(a[f].s2-a[f].s1 > 0&&a[f].now == 1&&cnt2 < n/2&&cnt1>0){
					cnt1--;
					cnt2++;
					ans += (a[f].s2-a[f].s1);
					f++;
				}
			}else{
				sort(a+1,a+n+1,cmp2);
				while(a[f].s3-a[f].s1 > 0&&a[f].now == 1&&cnt3 < n/2&&cnt1>0){
					cnt1--;
					cnt3++;
					ans += (a[f].s3-a[f].s1);
					f++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
