#include<bits/stdc++.h>//AC
#define int long long
#define INF 1145141919810
using namespace std;
int n,m,a[120001],xp;
int bro(int x){
	if(x==0)return n;
	else return x%n;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	xp=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==xp){
			xp=i;
			break;
		}
	cout<<((xp-1)/n)+1<<" ";
	if(((xp-1)/n)%2==0)cout<<bro(xp%n);
	else xp=n-xp%n+1,cout<<bro(xp%n);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
