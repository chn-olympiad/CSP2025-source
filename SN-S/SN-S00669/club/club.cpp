#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long d[N][4],q[N][4];
int num = 0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin>>d[i][j];
			}
			int s[4] = {0,d[i][1],d[i][2],d[i][3]};
			sort(s+1,s+1+3);
			for(int k=1;k<=3;k++){
				d[i][k] = s[k];
				d[i][k] = s[k];
				d[i][k] = s[k];
			}
		}
		for(int i=1;i<=n;i++){
			ans += d[i][3];
		}
		cout<<ans<<endl;
	}
	
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0 
