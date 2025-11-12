#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x0 XA_0
#define y0 YA_0
#define x1 XA_1
#define y1 YA_1
int n,m,mi;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>mi;
	a[1]=mi;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int lie=1,hang=0,f=1;
	for(int i=1;i<=n*m;i++){
		hang+=f;
		if(hang>n){
			if(lie%2==1){
				hang=n;
				lie++;
				f=-1;
			}else{
				hang=1;
				lie++;
				f=1;
			}
		}else if(hang<1){
			lie++;
			hang=1;
			f=1;
		}
		if(a[i]==mi)break;
	}
	cout<<lie<<' '<<hang;
	return 0;
}

