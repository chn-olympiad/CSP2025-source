#include<bits/stdc++.h>
using namespace std;
struct live{
	int a,b,c;
};
live p[100008];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int p[100008][3];
	int t,n;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		int ans=0;
		for(int j=0;j<n;j++){
			cin >> p[j].a >> p[j].b >> p[j].c;
			if(p[j].a>p[j].b && p[j].a>p[j].c ){
				ans +=p[j].a;
			}
			if(p[j].b>p[j].c && p[j].b>p[j].a ){
				ans+=p[j].b;
			}
			if(p[j].c>p[j].a && p[j].c>p[j].b ){
				ans+=p[j].c;
			}
		}
		cout << ans << endl;
		ans=0;
		}
		return 0;
	}
