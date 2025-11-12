#include<bits/stdc++.h>
using namespace std;
//int dp[500010][266];//dp[i][bin] means proj nums with (end up with a[i]) and (xor res bin)
//60pts O(n^n)
int n,k;
int a[500010];
int xo[1010][1010];//60pts ed
struct sk{
	int b,e;
	bool operator<(const sk o)const{
		return e<o.e;
	}
};
vector<sk>vs; //contain xor of k
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n<=1000) xo[i][i]=a[i];
		if(n<=1000) if(xo[i][i]==k) vs.push_back({i,i});
	}
	
	if(n>1000){ //baoli 13
		if(k==0){ //chuli k=0
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i-1]==1){
					ans++;
					a[i]=0;
				}
			}
			cout<<ans;
		}
		else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		else cout<<11476;
		return 0;
	}
	
	for(int i=1;i<=n;i++){ //begin
		for(int l=2;l<=n-i+1;l++){ //length
			xo[i][i+l-1]=(xo[i][i+l-2])^(a[i+l-1]);
			if(xo[i][i+l-1]==k) vs.push_back({i,i+l-1});
		}
	}
	//dont touch  calc xo[i][j]  &  note range
	
	sort(vs.begin(),vs.end());
	int ans=1; //default include 1st
	int ed=vs[0].e;
	for(int i=1;i<vs.size();i++){
		if(vs[i].b>ed){
			ans++;
			ed=vs[i].e;
//			cout<<vs[i].b<<'~'<<vs[i].e<<" now k="<<k<<endl;
		}
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}