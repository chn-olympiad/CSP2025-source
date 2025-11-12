#include <bits/stdc++.h>
using namespace std;
int t,n,ans,ans2,cnt1,cnt2,cnt3,sum;
const int N = 1e5+5;
struct member{
	bool tag;
	int a1,a2,a3;
}a[N];
struct member2{
	int type;
	int resource;
	int x;
}tmp[N],f[N*3];
void copy(int q){
	if (q == 1){
		for (int i = 1;i <= n;i++){
			tmp[i].type = 1;
			tmp[i].x = a[i].a1;
			tmp[i].resource = i;
		}
	}else if (q == 2){
		for (int i = 1;i <= n;i++){
			tmp[i].type = 2;
			tmp[i].x = a[i].a2;
			tmp[i].resource = i;
		}
	}else if (q == 3){
		for (int i = 1;i <= n;i++){
			tmp[i].type = 3;
			tmp[i].x = a[i].a3;
			tmp[i].resource = i;
		}
	}
	return;
}
void add(int start){
	for (int i = start;i <= start+n-1;i++){
		f[i].x = tmp[i-start+1].x;
		f[i].resource = tmp[i-start+1].resource;
		f[i].type = tmp[i-start+1].type;
	}
	return;
}
bool cmp(member2 m1,member2 m2){
	return m1.x>m2.x;
}
void reset(){
	ans = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0,sum = 0;
	for(int i = 1;i <= n;i++){
		a[i].tag = 0;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		copy(1);
		sort(tmp+1,tmp+n+1,cmp);
		add(1);
		copy(2);
		sort(tmp+1,tmp+n+1,cmp);
		add(n+1);
		copy(3);
		sort(tmp+1,tmp+n+1,cmp);
		add(n*2+1);
		sort(f+1,f+(n*3)+1,cmp);
		for (int k = 1;k <= n*3;k++){
			for (int i = k;i <= n*3 && !(sum == n);i++){
				if (!a[f[i].resource].tag){
					if (f[i].type == 1 && !(cnt1 == n/2)){
						ans2+=f[i].x;
						a[f[i].resource].tag = true;
						sum++;
						cnt1++;
						continue; 
					}
					if (f[i].type == 2 && !(cnt2 == n/2)){
						ans2+=f[i].x;
						a[f[i].resource].tag = true;
						sum++;
						cnt2++;
						continue; 
					}
					if (f[i].type == 3 && !(cnt3 == n/2)){
						ans2+=f[i].x;
						a[f[i].resource].tag = true;
						sum++;
						cnt3++;
						continue; 
					}
				}
			}
			if (ans2>ans){
				ans = ans2;
			}
			ans2 = 0;
			for(int i = 1;i <= n;i++){
				a[i].tag = 0;
			}
			cnt1 = 0,cnt2 = 0,cnt3 = 0,sum = 0;
		}
		cout << ans << endl;
		reset();
	}
	return 0;
}
