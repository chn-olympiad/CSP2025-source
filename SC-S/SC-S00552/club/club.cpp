#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

//int dp[N][105];
struct stu{
	int x,id;
}a[N],b[N],c[N];

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

bool cmp(stu l,stu r){
	if(l.x=r.x)return l.id>r.id;
	return l.x>r.x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		int ai=n/2;
		int bi=n/2;
		int ci=n/2;
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt==n)break;
			if(a[i].id!=b[i].id&&a[i].id!=c[i].id&&b[i].id!=c[i].id){
				if(ai>0){
					sum+=a[i].x;
					ai--;
					cnt++;
				}
				if(bi>0){
					sum+=b[i].x;
					bi--;
					cnt++;
				}
				if(ci>0){
					sum+=c[i].x;
					ci--;
					cnt++;
				}
			}else if(a[i].id==b[i].id&&a[i].id!=c[i].id){
				if(ci>0){
					sum+=c[i].x;
					ci--;
					cnt++;
				}
				if(a[i].x>b[i].x){
					if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else{
						if(bi>0){
							sum+=b[i].x;
							bi--;
							cnt++;
						}
					}
				}else{
					if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else{
						if(ai>0){
							sum+=a[i].x;
							ai--;
							cnt++;
						}
					}
				}
			}else if(a[i].id==c[i].id&&a[i].id!=b[i].id){
				if(bi>0){
					sum+=b[i].x;
					bi--;
					cnt++;
				}
				if(a[i].x>c[i].x){
					if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else{
						if(ci>0){
							sum+=c[i].x;
							ci--;
							cnt++;
						}
					}
				}else{
					if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else{
						if(ai>0){
							sum+=a[i].x;
							ai--;
							cnt++;
						}
					}
				}
			}else if(c[i].id==b[i].id&&a[i].id!=b[i].id){
				if(ai>0){
					sum+=a[i].x;
					ai--;
					cnt++;
				}
				if(c[i].x>b[i].x){
					if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else{
						if(bi>0){
							sum+=b[i].x;
							bi--;
							cnt++;
						}
					}
				}else{
					if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else{
						if(ci>0){
							sum+=c[i].x;
							ci--;
							cnt++;
						}
					}
				}
			}else{
				if(a[i].x>b[i].x&&b[i].x>c[i].x){
					if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else{
						ci--;
						cnt++;
						sum+=c[i].x;
					}
				}else if(a[i].x>c[i].x&&c[i].x>b[i].x){
					if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else{
						bi--;
						cnt++;
						sum+=b[i].x;
					}
				}else if(b[i].x>a[i].x&&a[i].x>c[i].x){
					if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else{
						ci--;
						cnt++;
						sum+=c[i].x;
					}
				}else if(b[i].x>c[i].x&&c[i].x>a[i].x){
					if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else{
						ai--;
						cnt++;
						sum+=a[i].x;
					}
				}else if(c[i].x>a[i].x&&c[i].x>b[i].x){
					if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else if(ai>0){
						ai--;
						cnt++;
						sum+=a[i].x;
					}else{
						bi--;
						cnt++;
						sum+=b[i].x;
					}
				}else if(c[i].x>b[i].x&&c[i].x>a[i].x){
					if(ci>0){
						ci--;
						cnt++;
						sum+=c[i].x;
					}else if(bi>0){
						bi--;
						cnt++;
						sum+=b[i].x;
					}else{
						ai--;
						cnt++;
						sum+=a[i].x;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}

	
	return  0;
}
//	while(T--){
//		int n;
//		cin>>n;
//		int a1i=n/2,b1i=n/2,c1i=n/2;
//		int a2i=n/2,b2i=n/2,c2i=n/2;
//		int a3i=n/2,b3i=n/2,c3i=n/2;
//		for(int i=1;i<=n;i++){
//			dp[0][a1i]=0;
//			dp[0][b2i]=0;
//			dp[0][c3i]=0;
//			cin>>a[i]>>b[i]>>c[i];
//			t[b[i]]++;
//			t[c[i]]++;
//		}
//		if(t[]){
//			
//		}else if(n<=200){
//			for(int i=1;i<=n;i++){
//				if(a1i>0)dp[i][a1i]=max(dp[i][a1i],dp[i-1][a1i--]+a[i]);
//				if(b1i>0)dp[i][a1i]=max(dp[i][a1i],dp[i-1][b1i--]+b[i]);
//				if(c1i>0)dp[i][a1i]=max(dp[i][a1i],dp[i-1][c1i--]+c[i]);
//			
//				if(a2i>0)dp[i][b2i]=max(dp[i][b2i],dp[i-1][a2i--]+a[i]);
//				if(b2i>0)dp[i][b2i]=max(dp[i][b2i],dp[i-1][b2i--]+b[i]);
//				if(c2i>0)dp[i][b2i]=max(dp[i][b2i],dp[i-1][c2i--]+c[i]);
//			
//				if(a3i>0)dp[i][c3i]=max(dp[i][c3i],dp[i-1][a3i--]+a[i]);
//				if(b3i>0)dp[i][c3i]=max(dp[i][c3i],dp[i-1][b3i--]+b[i]);
//				if(c3i>0)dp[i][c3i]=max(dp[i][c3i],dp[i-1][c3i--]+c[i]);
//			}
//			int mx=0;
//			for(int i=1;i<=n/2;i++){
//				mx=max(dp[n][i],mx);
//			}
//			cout<<mx<<"\n";
//		}
//		
//	}

