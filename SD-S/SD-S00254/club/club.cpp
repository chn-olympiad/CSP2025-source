#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
using namespace std;
#define int long long
const int N=1e5+5;
int n;
int a[N][3];
struct node{
	int x,id,y;
	bool operator < (const node &c) const{
		return x>c.x;
	}
}b[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    int limit=n/2;
    for(int i=1;i<=n;i++){
    	int max_val = max(a[i][0],max(a[i][1],a[i][2]));
    	int best_dept = -1;
        int best_advantage = -1;
        for (int j=0;j<3;j++) {
            int advantage=a[i][j];
            if (a[i][j]==max_val) {
                int second_max=-1;
                for (int k=0;k<3; k++) {
                    if (k!=j&&a[i][k]>second_max) {
                        second_max=a[i][k];
                    }
                }
                advantage=a[i][j]-second_max;
            } else {
                advantage=a[i][j]-max_val;
            }
            if (advantage>best_advantage) {
                best_advantage=advantage;
                best_dept=j;
            }
        }
        b[i]=(node){best_advantage, i, best_dept};
	}
    sort(b+1,b+n+1);
    
    vector<int> dept_count(3, 0);
    vector<int> assignment(n, -1);
    long long total_satisfaction = 0;
    
    for (int i=1;i<=n;i++) {
    	int advantage=b[i].x,person=b[i].id,dept=b[i].y;
        if (dept_count[dept] < limit) {
            assignment[person] = dept;
            dept_count[dept]++;
            total_satisfaction += a[person][dept];
        }
    }
    for (int i=1;i<=n;i++) {
        if (assignment[i]==-1) {
            int best_dept = -1;
            int best_value = -1;
            for (int j = 0; j < 3; j++) {
                if (dept_count[j] < limit && a[i][j] > best_value) {
                best_value = a[i][j];
                best_dept = j;
				}
            }
            if (best_dept != -1) {
                assignment[i] = best_dept;
                dept_count[best_dept]++;
                total_satisfaction += best_value;
            }
        }
	}
    cout<<total_satisfaction<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

