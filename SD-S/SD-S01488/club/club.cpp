#include<bits/stdc++.h>
using namespace std;
__int128 read(){
	char c;
	__int128 ans = 0;
	__int128 fl = 1;
	c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			fl *=-1;
		}
		c = getchar();
	}
	while(c<='9'&&c>='0'){
		ans*=10;
		ans += __int128(c-'0');
		c = getchar();
	}
	return ans;
}
void write(__int128 ans){
	if(ans<0){
		putchar('-');
		ans=-ans;
	}
	write(ans/10);
	putchar(char('0'+ans%10));
}
int n;
int a[100005][5];
int f[205][105][105][4];
priority_queue <int>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		int sum = 0;
		bool flag = 1;
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0){
				flag=0;
			}
			q.push(a[i][1]);
		}
		if(n>200&&flag){
			int ans = 0;
			int ji =0 ;
			while(!q.empty()){
				ans += q.top();
				if(ji >= n/2)ans -=q.top();
				ji++;
				q.pop();
			}
			cout << ans<<endl;
			continue;
		}
		for(int i =1;i <= n;i ++){
			for(int j = 0;j <=min(i,(n/2));j++){
				for(int k=0;k<=min(n/2,i-j);k++){
//					f[i][j][k][1] = -1;
//					f[i][j][k][2] = -1;
//					f[i][j][k][3] = -1;
					if(i-j-k > n/2){
						continue;
					}
//					f[i][j][k][1] = -1;
//					f[i][j][k][2] = -1;
//					f[i][j][k][3] = -1;
					if(j>0){
						if(j-1>0&&f[i-1][j-1][k][1]!=-1){
							f[i][j][k][1] = max(f[i][j][k][1],f[i-1][j-1][k][1]);
						}
						if(k>0&&f[i-1][j-1][k][2]!=-1){
							f[i][j][k][1] = max(f[i][j][k][1],f[i-1][j-1][k][2]);
						}
						if(i-j-k>0&&f[i-1][j][k][3]!=-1){
							f[i][j][k][1] = max(f[i][j][k][1],f[i-1][j-1][k][3]);
						}
						if(f[i][j][k][1]!=-1)f[i][j][k][1]+=a[i][1];
					}
					if(k>0){
						if(j>0&&f[i-1][j][k-1][1]!=-1){
							f[i][j][k][2] = max(f[i][j][k][2],f[i-1][j][k-1][1]);
						}
						if(k-1>0&&f[i-1][j][k-1][2]!=-1){
							f[i][j][k][2] = max(f[i][j][k][2],f[i-1][j][k-1][2]);
						}
						if(i-j-k>0&&f[i-1][j][k-1][3]!=-1){
							f[i][j][k][2] = max(f[i][j][k][2],f[i-1][j][k-1][3]);
						}
						if(f[i][j][k][2]!=-1)f[i][j][k][2]+=a[i][2];
					} 
					if(i-k-j>0){
						if(j>0&&f[i-1][j][k][1]!=-1){
							f[i][j][k][3] = max(f[i][j][k][3],f[i-1][j][k][1]);
						}
						if(k>0&&f[i-1][j][k][2]!=-1){
							f[i][j][k][3] = max(f[i][j][k][3],f[i-1][j][k][2]);
						}
						if(i-j-k-1>0&&f[i-1][j][k][3]!=-1){
							f[i][j][k][3] = max(f[i][j][k][3],f[i-1][j][k][3]);
						}
						if(f[i][j][k][3]!=-1)f[i][j][k][3]+=a[i][3];
					} 
				}
			}
		}
		int ans = -1; 
		for(int i = 0;i<=n/2;i++){
			for(int k = 0;k<=n/2;k++){
				int l = n-i-k;
				if(l>n/2)continue;
				if(i > 0){
					ans = max(ans,f[n][i][k][1]);
				}
				if(k>0){
					ans = max(ans,f[n][i][k][2]);
				}
				if(l>0){
					ans = max(ans,f[n][i][k][3]);
				}
			}
		}
		cout << ans<<endl;
//		for(int i =1;i <= n;i ++){
//			for(int j = 0;j <=min(i,(n/2));j++){
//				for(int k=0;k<=min(n/2,i-j);k++){
//					cout << "f["<<i<<"]["<<j<<"]["<<k<<"][1] = "<<f[i][j][k][1]<<endl; 
//					cout << "f["<<i<<"]["<<j<<"]["<<k<<"][2] = "<<f[i][j][k][2]<<endl; 
//					cout << "f["<<i<<"]["<<j<<"]["<<k<<"][3] = "<<f[i][j][k][3]<<endl; 
//				}
//			}
//		}
	} 
	
	return 0;
}
//Ren5Jie4Di4Ling5%
/*1
4 4 2 1 3 2 4 5 3 4 3 5 1
*/
