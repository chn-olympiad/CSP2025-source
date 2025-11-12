#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define ll long long
const int MAXN=1;
ll n,m,x,k,c,r,a[105];
bool cmp(ll a,ll b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	a[0]=x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			k=i;
			break;
		}
	}
	c=k/n+1;
	r=k%n;
	if(c%2==0){
		r=n-r;
	}else{
		r++;
	}
	cout<<c<<" "<<r;
	return 0;
}
