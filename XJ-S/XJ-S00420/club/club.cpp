#include<bits/stdc++.h> 
using namespace std;
int n;
int t;
int a[202020];//对1的满意度 
int b[202020];//对2的满意度 
int c[202020];//对3的满意度 
int vis[202020];//是否访问 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >>n;
		for(int i =1;i<=n;i++){
			vis[i] = 1;
		}
		//输入与初始化 
		for(int i = 1;i<= n;i++){
			cin >>a[i]>>b[i]>> c[i];
		}
		int A = 1;//只有a有值 
		int B = 1;//只有c无值 
		int C = 1;//只有b有值 
		int D = 1;//只有c有值 
		for(int i = 1;i<=n ;i++){
			if(b[i] == c[i]&&c[i]==0){
				A = 1;
			}else{
				A = 0;
				break;
			}
		}
		for(int i = 1;i<=n ;i++){
			if(a[i] == c[i]&&c[i]==0){
				C = 1;
			}else{
				C = 0;
				break;
			}
		}
		for(int i = 1;i<=n ;i++){
			if(b[i] == a[i]&&a[i]==0){
				D = 1;
			}else{
				D = 0;
				break;
			}
		}
		for(int i = 1;i<=n ;i++){ 
			if(c[i] == 0){
				B = 1;
			}else{
				B = 0;
				break;
			}
		}
		if(A == 1){//对A点偷分 
			int maxnn = 0;
			int ans = 0;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<a[j]&&vis[j] == 1){
						maxnn = a[j];
						vis[j] = 0;
					}
				}
				ans += maxnn;
			}
			cout <<ans;//输出 
		}
		else if(C == 1){
			int maxnn = 0;
			int ans = 0;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<b[j]&&vis[j] == 1){
						maxnn = b[j];
						vis[j] = 0;
					}
				}
				ans += maxnn;
			}
			cout <<ans;//输出 
		}
		else if(D == 1){ 
			int maxnn = 0;
			int ans = 0;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<c[j]&&vis[j] == 1){
						maxnn = c[j];
						vis[j] = 0;
					}
				}
				ans += maxnn;
			}
			cout <<ans;//输出 
		}
		else if(B == 1){//对B点偷分 
			int maxnz = 0;
			int ans1 = 0;
			for(int i = 1;i<=n/2;i++){
				maxnz = 0;
				for(int j = 1;j<= n;j++){
					if(maxnz<a[j]&&vis[j] == 1){
						maxnz = a[j];
						vis[j] = 0;
					}
				}
				ans1 += maxnz;
			}
			for(int i = 1;i<=n;i++){
				if(vis[i] == 1){
					ans1 += b[i];
				}
			}
			int ans2 = 0;
			int maxny = 0;
			for(int i = 1;i<=n/2;i++){
				maxny = 0;
				for(int j = 1;j<= n;j++){
					if(maxny<b[j]&&vis[j] == 1){
						maxny = b[j];
						vis[j] = 0;
					}
				}
				ans2 += maxny;
			}
			for(int i = 1;i<=n;i++){
				if(vis[i] == 1){
					ans2 += a[i];
				}
			}
			int ans = max(ans1,ans2);
			cout <<ans;//输出 
		}
		else if(n == 2){
			int ans = 0;
			int ans1 = max(a[1]+c[2],a[1]+b[2]);
			int ans2 = max(b[1]+c[2],b[1]+a[2]);
			int ans3 = max(c[1]+b[2],c[1]+a[2]);
			ans = max(ans1,ans2);
			ans = max(ans3,ans);
			cout <<ans;	//输出 
		}	
		else {
			int ans = 0;
			int ansl = 0;
			int ansm = 0;
			int ansr = 0;
			int maxnn = 0;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<a[j]&&vis[j] == 1){
						maxnn = a[j];
						vis[j] = 0;
					}
				}
				ansl += maxnn;
			}
			for(int j = 1;j<= n;j++){
				if(maxnn<b[j]&&vis[j] == 1){
					maxnn = b[j];
					vis[j] = 0;
				}
			}
			ansl += maxnn;
			for(int j = 1;j<= n;j++){
				if(maxnn<c[j]&&vis[j] == 1){
					maxnn = c[j];
					vis[j] = 0;
				}
			}
			ansl += maxnn;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<b[j]&&vis[j] == 1){
						maxnn = b[j];
						vis[j] = 0;
					}
				}
				ansm += maxnn;
			}
			for(int j = 1;j<= n;j++){
				if(maxnn<a[j]&&vis[j] == 1){
					maxnn = a[j];
					vis[j] = 0;
				}
			}
			ansm += maxnn;
			for(int j = 1;j<= n;j++){
				if(maxnn<c[j]&&vis[j] == 1){
					maxnn = c[j];
					vis[j] = 0;
				}
			}
			ansm += maxnn;
			for(int i = 1;i<=n/2;i++){
				maxnn = 0;
				for(int j = 1;j<= n;j++){
					if(maxnn<c[j]&&vis[j] == 1){
						maxnn = c[j];
						vis[j] = 0;
					}
				}
				ansr += maxnn;
			}
			for(int j = 1;j<= n;j++){
				if(maxnn<b[j]&&vis[j] == 1){
					maxnn = b[j];
					vis[j] = 0;
				}
			}
			ansl += maxnn;
			for(int j = 1;j<= n;j++){
				if(maxnn<a[j]&&vis[j] == 1){
					maxnn = a[j];
					vis[j] = 0;
				}
			}
			ansr += maxnn;
			ans = max(ansr,ansm);
			ans = max(ans,ansl);
			cout <<ans;//输出 
		}
	}
	return 0;
}
