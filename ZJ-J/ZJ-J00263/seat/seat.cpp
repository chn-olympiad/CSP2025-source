#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ull unsigned long long
using namespace std;
const int N=1e6+10;
int n,m;
int k;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	int x=1,r=1,f=1;
	for (int i=n*m;i>=1;i--){
		if (k==a[i]) break;
		if (f==1){
			if (r<n) r++;
			else {
				f=0;
				x++;
			}
			
		}
		else{
			if (r>1) r--;
			else {
				f=1;
				x++;
			}
		}
	}
	cout<<x<<' '<<r;
	return 0;
}
