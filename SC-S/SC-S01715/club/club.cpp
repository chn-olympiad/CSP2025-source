#include <bits/stdc++.h>//背包 
using namespace std;
int n,a[100005][3],num[100005][3],T,f[100005][5];
int ans = 0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
        ans = 0;
		memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		f[0][1] = 0;
		f[0][2] = 0;
		f[0][3] = 0;
		int k = n / 2;//第I个人在第j个的最大和 
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				for(int m = 1;m <= 3;m++){
					f[i][j] = max(f[i - 1][m] + a[i][j],f[i][j]);
					//cout << f[i][j] << endl;
				}			 
			}
		}
		for(int i = 1;i <= 3;i++){
			if(num[n][i] > k){
				f[n][i] = 0;
			}
		}
		for(int i = 1;i <= 3;i++){
			if(i == 1) continue;
			ans = max(f[n][i],ans);
		}
		cout << ans << endl;
		//for(int i = 1;i <= n;i++){
			//for(int j = 1;j <= 3;j++)
			//cout << f[i][j] << " ";
			//cout << endl;
		//}
	}	
	return 0;
}