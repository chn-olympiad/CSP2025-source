#include<bits/stdc++.h>

#define ll long long

using namespace std;
/*

//非常像dp
//[i]//第几个
//[j]//占几个位置最大
//[k]//被分到机组
//dp[i][j][k]
//遍历一遍其他组中
//
//先等等
//孤立地看问题
//就是背包
//
//限制：
//同一个数只能取一次
//那就分别算这个数

三个优先队列



*/

int n;
int a[110000][11];
ll dp[1100][1100][11];
int t;

struct fu {

	ll num;
	int x;

	bool operator < (const fu &a)const {

		return a.num<num;

	}


};

int ii[11];
ll ss[11];

priority_queue<fu> q;
ll aaa=0;
void f(int x) {
//	cout<<ss[1]<<" "<<ss[2]<<" "<<ss[3]<<endl;
	if(x==n){
		
		aaa=max(aaa,ss[1]+ss[2]+ss[3]);
//		cout<<aaa;
	}

	for(int i=x+1; i<=n; i++) {

		for(int j=1; j<=3; j++) {

			if(ii[j]<n/2) {

				ii[j]++;
				ss[j]+=a[i][j];
				f(i);
				ii[j]--;
				ss[j]-=a[i][j];
			}

		}
	}

}

int main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>t;

	while(t--) {

		cin>>n;
		int num30=0;
		for(int i=1; i<=n; i++) {



			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(!a[i][3])num30++;




		}
		if(n==2) {

			if(max(a[1][1],max(a[1][2],a[1][3]))==a[1][1]) {

				cout<<max(a[2][2],a[2][3])+a[1][1]<<endl;

			} else if(max(a[1][1],max(a[1][2],a[1][3]))==a[1][2]) {

				cout<<max(a[2][1],a[2][3])+a[1][2]<<endl;

			} else {

				cout<<max(a[2][1],a[2][2])+a[1][3]<<endl;

			}

		} else if(num30==n) {
			ll num1=0;
			ll num2=0;
			int id=0;
			for(int i=1; i<=n; i++) {

				if(id<n/2) {

					q.push({a[i][1],i});
					id++;
					num1+=a[i][1];

				} else {

					if(q.top().num<a[i][1]) {

						num1+=a[i][1]-q.top().num;
						num2+=a[q.top().x][2];
						q.pop();
						q.push({a[i][1],i});
					} else num2+=a[i][2];

				}

			}
			num1+=num2;
			cout<<num1<<endl;

		} else if(n<=4) {

			for(int x=1; x<=n; x++) {

				for(int j=1; j<=3; j++) {

					if(ii[j]<n/2) {

						ii[j]++;
						ss[j]+=a[x][j];
						f(x);
						ii[j]--;
						ss[j]-=a[x][j];
					}

				}
			}
			cout<<aaa<<endl;
			aaa=0;

		} else {


			for(int i=1; i<=n; i++) {

				for(int j=1; j<=n/2; j++) {

					dp[i][j][1]=max(dp[i-1][j][1],max(dp[i-1][j-1][1],max(dp[i-1][j][2],dp[i-1][j][3]))+a[i][1]);
					dp[i][j][2]=max(dp[i-1][j][2],max(dp[i-1][j-1][2],max(dp[i-1][j][1],dp[i-1][j][3]))+a[i][2]);
					dp[i][j][3]=max(dp[i-1][j][3],max(dp[i-1][j-1][3],max(dp[i-1][j][2],dp[i-1][j][1]))+a[i][3]);

//				cout<<i<<" "<<j<<" "<<max(dp[i-1][j-1][2],max(dp[i-1][j][1],dp[i-1][j][3]))<<" "<<a[i][2]<<endl;
//				cout<<dp[i][j][2]<<" ";
				}
//				cout<<dp[i][1][1]<<" "<<dp[i][2][1]<<" "<<dp[i][1][2]<<" "<<dp[i][2][2]<<" "<<dp[i][1][3]<<" "<<dp[i][2][3]<<endl;
//			cout<<endl;

			}
			cout<<max(dp[n][n/2][1],max(dp[n][n/2][2],dp[n][n/2][3]))<<endl;

		}




	}




	return 0;
}
