#include<bits/stdc++.h>
using namespace std;

int a[100001][4];
int sum[100001] = {0};
int ans = 0;
int vis[4] = {0};


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int t;
	cin>>t;
	cin>>n;
	int check = n/2;
	for(int s = 1;s <= t;s++){
			
		
		for(int i = 1;i <= n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	
	
	for(int i = 1; i <= n;i++){
		for(int j = 1;j <= 3; j++){
			if(vis[j] >= check){
				if(j == 3){
					sum[s]+= ans;
					ans = 0;
					continue;
			}	
			
				else{
					continue;
			}	
			}
		
			ans = max(ans,a[i][j]);
			if(j == 3){
				for(int k = 1;k <= 3;k++){
					if(ans == a[i][k]){
						vis[k]++;
					}
				}
				sum[s] += ans;
				ans = 0;
			}
	}
		
}
	for(int i = 1; i <= 4;i++){
		vis[i] = 0;
	}
		
}
	for(int i = 1; i <= t;i++){
		cout<<sum[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

