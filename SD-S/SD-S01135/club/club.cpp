#include<bits/stdc++.h>
using namespace std;
long long n,ans=-1,t,aa,bb,cc;
long long st[100001][6];
void sou(long long biao,long long anss,long long a,long long b,long long c) {
	if(a>n/2||b>n/2||c>n/2) return ;
	for(int i=biao; i<=n; i++) {
		if(st[i][1]>=st[i][2]&&st[i][1]>=st[i][3]) {
			sou(i+1,anss+st[i][1],a+1,b,c);
			if(st[i][2]>=st[i][3]) {
				sou(i+1,anss+st[i][2],a,b+1,c);
			} else {
				sou(i+1,anss+st[i][3],a,b,c+1);
			}
		}
		else if(st[i][2]>=st[i][1]&&st[i][2]>=st[i][3]) {
			sou(i+1,anss+st[i][2],a,b+1,c);
			if(st[i][1]>=st[i][3]) {
				sou(i+1,anss+st[i][1],a+1,b,c);
			} else {
				sou(i+1,anss+st[i][3],a,b,c+1);
			}
		} else {
			sou(i+1,anss+st[i][3],a,b,c+1);
			if(st[i][1]>=st[i][2]) {
				sou(i+1,anss+st[i][1],a+1,b,c);
			} else {
				sou(i+1,anss+st[i][2],a,b+1,c);
			}
		}
	}
	ans=max(ans,anss);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=-1;
		for(int i=1; i<=n; i++) {
			cin>>st[i][1]>>st[i][2]>>st[i][3];

		}

		sou(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
