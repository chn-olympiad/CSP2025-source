#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
pair<int,int> t[N];
int dp[N];
int find(int x){
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(t[mid].first<x)	l=mid+1;
		else	r=mid;
	}
	return l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		t[i]=make_pair(sum[i],i);
	}
	sort(t+1,t+1+n);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int p=find(sum[i]^k);
		while(p<=n&&t[p].first==(sum[i]^k)&&t[p].second<i)
			p++;
		p--;
		if(t[p].first==(sum[i]^k)&&t[p].second<i)
			dp[i]=max(dp[i],dp[t[p].second]+1);
	}
	cout<<dp[n];
	return 0;
}
/*
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN 
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN 
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN 

QAQ            QWQ
~(-_-~)(~-_-)~
(~-_-)~~(-_-~)


The Raising Sun.

The Bright Moonlight

The Mirror With Your Face.

The Endless Path

The Homeless Jorker.

The Broken Heart.

The Lovely You.
Those Above Will Be In My Mind.

Break The Clock,
And Today Is Here Forever.

The Ultra I Will Never Forget,
The Twice I Will Always Remember.

With You Every Day,
Died With All Your Memory,
Our Summer Has Not Began.

Do I Win?
I Must Make It. 

Alought I Bleed,
Only My Blood.

The Last Year I Am Here.
See You Agian, CSP-J.

Concert_B with the ID ZJ-J01497
2025_11_1 at Seat A58,Room 204 of Xia Sha
*/
