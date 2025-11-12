#include<bits/stdc++.h>
using namespace std;
long long t,n,mx[100005][5],vis[5],ans=0,k,sum=0,m1[100005],m2[100005],m3[100005];
bool A=1,B=1,C=1;

void dfs(int x){
	if(x>n){
		ans=max(ans,sum);
		sum=0;
		return;
	}
	for(int i=1;i<=3;i+=2){
		if(vis[i]<k){
			sum+=mx[x][i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
	}
}
void kfs(int x){
	if(x>n){
		ans=max(ans,sum);
		sum=0;
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<k){
			sum+=mx[x][i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
	}
}
void kfc(int x){
	if(x>n){
		ans=max(ans,sum);
		sum=0;
		return;
	}
	for(int i=2;i<=3;i++){
		if(vis[i]<k){
			sum+=mx[x][i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
	}
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	
	while(t--){
		A=1,B=1,C=1;
		cin >> n;
		k=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> mx[i][j];
			}
			if(mx[i][2]>0 ){
				A=0;
				C=0;
			}
			if(mx[i][3]>0){
				A=0;
				B=0;
			}
			if(mx[i][1]>0){
				B=0;
				C=0;
			}
		}
		if(A==1){
			for(int i=1;i<=n;i++){
				m1[i] = mx[i][1];
			}
			sort(m1+1,m1+n+1);
			for(int i=k+1;i<=n;i++){
				ans+=m1[i];
			}
		}
		else if(B==1){
			ans = 0;
			for(int i=1;i<=n;i++){
				m2[i] = mx[i][2];
			}
			sort(m2+1,m2+n+1);
			for(int i=k+1;i<=n;i++){
				ans+=m2[i];
			}
		}
		else if(C==1){
			for(int i=1;i<=n;i++){
				m3[i] = mx[i][3];
			}
			sort(m3+1,m3+n+1);
			for(int i=k+1;i<=n;i++){
				ans+=m3[i];
			}
		}
		else{
			dfs(1);
			kfs(1);
			kfc(1);
		}
		cout << ans << endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}





