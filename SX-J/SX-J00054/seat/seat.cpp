#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'

using namespace std;

typedef pair<int,int> PII;

const int N=100+10;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int g[11][11];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];

//	cout<<x<<endl;

	sort(a+1,a+n*m+1,cmp);
	/*
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	*/
	int idx=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				idx++;
				g[i][j]=a[idx];
//				cout<<a[idx]<<" "<<i<<" "<<j<<endl;
				if(a[idx]==x){
//					cout<<a[idx]<<" "<<x<<endl;
					cout<<i<<" "<<j<<endl;
					return 0;
				}

			}
		}else{
			for(int j=1;j<=n;j++){
				idx++;
				g[i][j]=a[idx];
//				cout<<a[idx]<<" "<<i<<" "<<j<<endl;
				if(a[idx]==x){
//					cout<<a[idx]<<" "<<x<<endl;
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/