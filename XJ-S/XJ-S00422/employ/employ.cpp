#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
int n,m,k;
string a;
int c[N],di[N],day,num,ans;
void dp(int d,int r){
	if(r>n||d>day){
		if(num>=m){
			ans++;
		}
		return ;
	}
	if(c[r]>di[d]){
		num++;
		dp(d+1,r+1);
	}
	else if(c[r]<=di[d]){
		dp(d,r+1);
		dp(d+1,r+1);
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=0;i<a.size();i++){
		di[i+1]=!(0-'0'+a[i]);
	    day++;
	}
	for(int i=2;i<=day;i++) di[i]+=di[i-1];
	dp(1,1);
	cout<<ans;
	return 0;
}
