#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<ll>qa;
priority_queue<ll>qb;
priority_queue<ll>qc;
ll n,x,y,z,ans;
int T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		while(!qa.empty())qa.pop();
		while(!qb.empty())qb.pop();
		while(!qc.empty())qc.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				qa.push(max(y,z)-x);
				ans+=x;
				if(qa.size()>n/2){
					ans+=qa.top();
					qa.pop();
				}
			}
			else if(y>=x&&y>=z){
				qb.push(max(x,z)-y);
				ans+=y;
				if(qb.size()>n/2){
					ans+=qb.top();
					qb.pop();
				}
			}
			else{
				qc.push(max(y,x)-z);
				ans+=z;
				if(qc.size()>n/2){
					ans+=qc.top();
					qc.pop();
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
2 14 18
2 15 16
2 6 16
2 10 20
8 10 5
3 14 17
6 13 17
9 1 4
16 5 11
*/
