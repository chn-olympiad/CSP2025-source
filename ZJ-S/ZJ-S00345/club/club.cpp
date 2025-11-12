#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
const int N = 1e5+5;
const int M = 1e3+5;
void solve(){
	int n; cin>>n;
	vi a1(n),a2(n),a3(n);
	for(int i=0;i<n;i++)
		cin>>a1[i]>>a2[i]>>a3[i];
	int m=n/2;
	int b1=0,b2=0,b3=0;
	int c1=0,c2=0,c3=0;
	for(int i=0;i<n;i++){
		int d=max(a1[i],max(a2[i],a3[i]));
		if(d==a1[i]) b1+=d,c1++;
		else if(d==a2[i]) b2+=d,c2++;
		else b3+=d,c3++;
	}
	int ans=b1+b2+b3;
	if(c1<=m&&c2<=m&&c3<=m){
		cout<<"\n\n\n"<<ans<<"\n\n\n";
		return;
	}
	int cu[n+5][5];
	for(int i=0;i<n;i++){
		cu[i][0]=abs(a1[i]-a2[i]);
		cu[i][1]=abs(a1[i]-a3[i]);
		cu[i][2]=abs(a2[i]-a3[i]);
	}
	if(c1>m){
		int md=c1-m,dy[n+5];
		for(int i=0;i<n;i++)
			dy[i]=min(cu[i][0],cu[i][1]);
		sort(dy,dy+n);
		int dyn=0;
		for(int i=0;i<md;i++)
			dyn+=dy[i];
		cout<<"\n\n\n"<<ans-dyn<<"\n\n\n";
		return;
	}else if(c2>m){
		int md=c2-m,dy[n+5];
		for(int i=0;i<n;i++)
			dy[i]=min(cu[i][0],cu[i][2]);
		sort(dy,dy+n);
		int dyn=0;
		for(int i=0;i<md;i++)
			dyn+=dy[i];
		cout<<"\n\n\n"<<ans-dyn<<"\n\n\n";
		return;
	}else if(c3>m){
		cout<<ans<<"\n\n\n\n\n";
		int md=c3-m,dy[n+5];
		for(int i=0;i<n;i++)
			dy[i]=min(cu[i][1],cu[i][2]);
		sort(dy,dy+n);
		int dyn=0;
		for(int i=0;i<md;i++)
			dyn+=dy[i];
		cout<<"\n\n\n"<<ans-dyn<<"\n\n\n";
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
