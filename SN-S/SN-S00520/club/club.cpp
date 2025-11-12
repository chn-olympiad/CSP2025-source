#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n,a,b,c,ans;
int student[MAXN][3];

bool telia,telib;
int xingzhia[MAXN];
int xingzhib[MAXN][2];

void dp(){
	
}

bool cmp(int x,int y) {
	return x > y;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		n = 0,a = 0,b = 0,c = 0,ans = 0;
		telia = true;
		telib = true;
		cin >> n;
		for(int i = 0;i <= n; i++) {
			student[i][0] = 0;
			student[i][1] = 0;
			student[i][2] = 0;
		}
		for(int i = 0;i < n; i++) {
			cin >> student[i][0] >> student[i][1] >> student[i][2];
			if(student[i][1]!=0 && student[i][2]!=0) telia = false;
			if(student[i][2]!=0) telib = false;
		}
		if(n==2) {
			ans = max(ans,student[0][0]+student[1][1]);
			ans = max(ans,student[0][0]+student[1][2]);
			ans = max(ans,student[0][1]+student[1][0]);
			ans = max(ans,student[0][1]+student[1][2]);
			ans = max(ans,student[0][2]+student[1][0]);
			ans = max(ans,student[0][2]+student[1][1]);
			cout << ans << endl;
		}
		if(n==4) {
			//0 and 1
			ans = max(ans,student[0][0]+student[1][0]+student[2][1]+student[3][1]);
			ans = max(ans,student[0][0]+student[1][0]+student[2][1]+student[3][2]);
			ans = max(ans,student[0][0]+student[1][0]+student[2][2]+student[3][1]);
			ans = max(ans,student[0][0]+student[1][0]+student[2][2]+student[3][2]);
			
			ans = max(ans,student[0][1]+student[1][1]+student[2][0]+student[3][0]);
			ans = max(ans,student[0][1]+student[1][1]+student[2][0]+student[3][2]);
			ans = max(ans,student[0][1]+student[1][1]+student[2][2]+student[3][0]);
			ans = max(ans,student[0][1]+student[1][1]+student[2][2]+student[3][2]);
			
			ans = max(ans,student[0][2]+student[1][2]+student[2][0]+student[3][0]);
			ans = max(ans,student[0][2]+student[1][2]+student[2][0]+student[3][1]);
			ans = max(ans,student[0][2]+student[1][2]+student[2][1]+student[3][0]);
			ans = max(ans,student[0][2]+student[1][2]+student[2][1]+student[3][1]);
			//0 and 2
			ans = max(ans,student[0][0]+student[2][0]+student[1][1]+student[3][1]);
			ans = max(ans,student[0][0]+student[2][0]+student[1][1]+student[3][2]);
			ans = max(ans,student[0][0]+student[2][0]+student[1][2]+student[3][1]);
			ans = max(ans,student[0][0]+student[2][0]+student[1][2]+student[3][2]);
			
			ans = max(ans,student[0][1]+student[2][1]+student[1][0]+student[3][0]);
			ans = max(ans,student[0][1]+student[2][1]+student[1][0]+student[3][2]);
			ans = max(ans,student[0][1]+student[2][1]+student[1][2]+student[3][0]);
			ans = max(ans,student[0][1]+student[1][1]+student[1][2]+student[3][2]);
			
			ans = max(ans,student[0][2]+student[2][2]+student[1][0]+student[3][0]);
			ans = max(ans,student[0][2]+student[2][2]+student[1][0]+student[3][1]);
			ans = max(ans,student[0][2]+student[2][2]+student[1][1]+student[3][0]);
			ans = max(ans,student[0][2]+student[2][2]+student[1][1]+student[3][1]);
			//0 and 3
			ans = max(ans,student[0][0]+student[3][0]+student[1][1]+student[2][1]);
			ans = max(ans,student[0][0]+student[3][0]+student[1][1]+student[2][2]);
			ans = max(ans,student[0][0]+student[3][0]+student[1][2]+student[2][1]);
			ans = max(ans,student[0][0]+student[3][0]+student[1][2]+student[2][2]);
			
			ans = max(ans,student[0][1]+student[3][1]+student[1][0]+student[2][0]);
			ans = max(ans,student[0][1]+student[3][1]+student[1][0]+student[2][2]);
			ans = max(ans,student[0][1]+student[3][1]+student[1][2]+student[2][0]);
			ans = max(ans,student[0][1]+student[3][1]+student[1][2]+student[2][2]);
			
			ans = max(ans,student[0][2]+student[3][2]+student[1][0]+student[2][0]);
			ans = max(ans,student[0][2]+student[3][2]+student[1][0]+student[2][1]);
			ans = max(ans,student[0][2]+student[3][2]+student[1][1]+student[2][0]);
			ans = max(ans,student[0][2]+student[3][2]+student[1][1]+student[2][1]);
			
			//1 and 2
			ans = max(ans,student[1][0]+student[2][0]+student[0][1]+student[3][1]);
			ans = max(ans,student[1][0]+student[2][0]+student[0][1]+student[3][2]);
			ans = max(ans,student[1][0]+student[2][0]+student[0][2]+student[3][1]);
			ans = max(ans,student[1][0]+student[2][0]+student[0][2]+student[3][2]);
			
			ans = max(ans,student[1][1]+student[2][1]+student[0][0]+student[3][0]);
			ans = max(ans,student[1][1]+student[2][1]+student[0][0]+student[3][2]);
			ans = max(ans,student[1][1]+student[2][1]+student[0][2]+student[3][0]);
			ans = max(ans,student[1][1]+student[1][1]+student[0][2]+student[3][2]);
			
			ans = max(ans,student[1][2]+student[2][2]+student[0][0]+student[3][0]);
			ans = max(ans,student[1][2]+student[2][2]+student[0][0]+student[3][1]);
			ans = max(ans,student[1][2]+student[2][2]+student[0][1]+student[3][0]);
			ans = max(ans,student[1][2]+student[2][2]+student[0][1]+student[3][1]);
			
			//1 and 3
			ans = max(ans,student[1][0]+student[3][0]+student[0][1]+student[2][1]);
			ans = max(ans,student[1][0]+student[3][0]+student[0][1]+student[2][2]);
			ans = max(ans,student[1][0]+student[3][0]+student[0][2]+student[2][1]);
			ans = max(ans,student[1][0]+student[3][0]+student[0][2]+student[2][2]);
			
			ans = max(ans,student[1][1]+student[3][1]+student[0][0]+student[2][0]);
			ans = max(ans,student[1][1]+student[3][1]+student[0][0]+student[2][2]);
			ans = max(ans,student[1][1]+student[3][1]+student[0][2]+student[2][0]);
			ans = max(ans,student[1][1]+student[3][1]+student[0][2]+student[2][2]);
			
			ans = max(ans,student[1][2]+student[3][2]+student[0][0]+student[2][0]);
			ans = max(ans,student[1][2]+student[3][2]+student[0][0]+student[2][1]);
			ans = max(ans,student[1][2]+student[3][2]+student[0][1]+student[2][0]);
			ans = max(ans,student[1][2]+student[3][2]+student[0][1]+student[2][1]);
			
			//2 and 3
			ans = max(ans,student[2][0]+student[3][0]+student[0][1]+student[1][1]);
			ans = max(ans,student[2][0]+student[3][0]+student[0][1]+student[1][2]);
			ans = max(ans,student[2][0]+student[3][0]+student[0][2]+student[1][1]);
			ans = max(ans,student[2][0]+student[3][0]+student[0][2]+student[1][2]);
			
			ans = max(ans,student[2][1]+student[3][1]+student[0][0]+student[1][0]);
			ans = max(ans,student[2][1]+student[3][1]+student[0][0]+student[1][2]);
			ans = max(ans,student[2][1]+student[3][1]+student[0][2]+student[1][0]);
			ans = max(ans,student[2][1]+student[3][1]+student[0][2]+student[1][2]);
			
			ans = max(ans,student[2][2]+student[3][2]+student[0][0]+student[1][0]);
			ans = max(ans,student[2][2]+student[3][2]+student[0][0]+student[1][1]);
			ans = max(ans,student[2][2]+student[3][2]+student[0][1]+student[1][0]);
			ans = max(ans,student[2][2]+student[3][2]+student[0][1]+student[1][1]);
			
			cout << ans << endl;
		}
		if(telia) {
			for(int i = 0;i < n; i++) {
				xingzhia[i] = student[i][0];
			}
			sort(xingzhia,xingzhia+n,cmp);
			for(int i = 0;i < n/2; i++) {
				ans += xingzhia[i];
			}
			cout << ans << endl;
		}
		if(telib && telia==false) {
			for(int i = 0;i < n; i++) {
				xingzhib[i][0] = student[i][0];
				xingzhib[i][1] = student[i][1];
			}
			
			dp();
			
			cout << ans << endl;
		}
	}
	
	return 0;
}
