#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200100;
int T;
int n,c,i;
struct no{
	int k1,k2,k3;
}a[MAXN];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		c=0;
		int f1=0,f2=0,f3=0;
		priority_queue<int,vector<int>,greater<int> > q[10];
		for(i=1;i<=n;i++){
			cin>>a[i].k1>>a[i].k2>>a[i].k3;
			int x=max(a[i].k1,max(a[i].k2,a[i].k3));
			if(a[i].k1==x){
				f1++;
				c+=a[i].k1;
				if(a[i].k2>a[i].k3) q[1].push(a[i].k1-a[i].k2);
				else q[1].push(a[i].k1-a[i].k3);
			}
			else if(a[i].k2==x){
				f2++;
				c+=a[i].k2;
				if(a[i].k1>a[i].k3) q[2].push(a[i].k2-a[i].k1);
				else q[2].push(a[i].k2-a[i].k3);
			}
			else{
				f3++;
				c+=a[i].k3;
				if(a[i].k1>a[i].k2) q[3].push(a[i].k3-a[i].k1);
				else q[3].push(a[i].k3-a[i].k2);
			}
		}
		while(f1*2>n){
			c-=q[1].top();
			q[1].pop();
			f1--;
		}
		while(f2*2>n){
			c-=q[2].top();
			q[2].pop();
			f2--;
		}
		while(f3*2>n){
			c-=q[3].top();
			q[3].pop();
			f3--;
		}
		cout<<c<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
