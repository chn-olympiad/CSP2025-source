#include<bits/stdc++.h>
using namespace std;
long long a,b,ans=0;
string c;
char d[10000];
int x[10000],dp[10000];
void dfs(int day,int g,int w) {
day++;
	int n=w;
	for(int i=0; i<a; i++) {
		if(dp[i]==0&&x[i]<=w) {
			n++;
			dp[i]=1;
		
		}
	}
	w=n;
	for(int i; i<a; i++) {
		if(dp[i]==0) {
		
			if(d[day]=='1') {
				//	cout<<"aaa ";
				g++;
				dp[i]=1;
				//	cout<<g<<' '<<day<<"->";
				dfs(day,g,w);
				if(g>=b) {
					ans++;
				//	cout<<"\n";
				}
			
				g--;
				
				dp[i]=0;

			} else {
				w++;
				dp[i]=1;
				dfs(day,g,w);
				w--;
				dp[i]=0;
			}
		}
	}
	return;
}
int main() {
	freopen("emple.in","r",stdin);
		freopen("emple.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=0; i<a; i++) {

		cin>>x[i];
	}
	int u=c.size();
	for(int i=0; i<u; i++) {
		d[i]=c[i];
	}
	dfs(0,0,0);
	cout<<ans;
	    return 0;
}
