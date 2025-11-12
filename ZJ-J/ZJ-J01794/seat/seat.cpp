#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int a[N];
int b[N][N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin>>a[i];
	int k = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}

	cout<<(k+n-1)/n<<' ';
	if((k+n-1)/n % 2==0) cout<<n-k%n+1;
	else cout<<(k<=n?k:k%n);

	return 0;
}

