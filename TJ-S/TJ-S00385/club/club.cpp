#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int x[100001];
int n;
void solve1(){
	int ans = 0,a1 = 0,a2 = 0,a3 = 0;
	memset(x,0,sizeof x);
	for(int i = 1;i<=n;i++){
		int p = max(a[i][1],max(a[i][2],a[i][3]));
		x[i] = p;
		ans+=x[i];
		if(p==a[i][1])a1++;
		else if(p==a[i][2])a2++;
		else a3++;
	}
	if(a1>n/2){
		while(a1>n/2){
			int c = -10000000;
			for(int i = 1;i<=n;i++){
				if(x[i]==a[i][1]) c = max(c,max(a[i][2],a[i][3])-a[i][1]);
			}
			ans += c;
			a1--;
		}
	}else if(a2>n/2){
		while(a2>n/2){
			int c = -10000000;
			for(int i = 1;i<=n;i++){
				if(x[i]==a[i][2]) c = max(c,max(a[i][1],a[i][3])-a[i][2]);
			}
			ans += c;
			a2--;
		}
	}else if(a3>n/2){
		while(a3>n/2){
			int c = -10000000;
			for(int i = 1;i<=n;i++){
				if(x[i]==a[i][3]) c = max(c,max(a[i][2],a[i][1])-a[i][3]);
			}
			ans += c;
			a3--;
		}
	}
	//cout << "    ";
	cout << ans << "\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t!=0){
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		solve1();
		t--;
	}
	return 0;
}
