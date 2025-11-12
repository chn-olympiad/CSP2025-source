#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+5;
int n,m;
vector<pair<int,int> > a;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		a.push_back(make_pair(-x,i));
	}
	sort(a.begin(),a.end());
	int u=0;
	for(int i=0;i<n*m;i++)
		if(a[i].second==1)
			u=i+1;
	int x=u/(2*n)*2+1;
	u%=2*n;
	if(u>n)	cout<<x+1<<' '<<2*n-u;
	else	cout<<x<<' '<<u;
	return 0;
}
/*
Who Is Here?

Whose Heart In My Mind?

When It Was Discovered?

No Method.

No Effort.

No Wishes.

And No Teers.

Somewhere

Whis Firework

In My Soal

Is the River Chenxi

Forest With Firefly

Once Meet Only Whis

Poems Have No Eye

Code Have A Sad Pomt

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%        %%%%%%      %%%%%%%%%%%%%%%%%%      %
%%%%    %%%%%%%%%%   %%%%%%%%%%%%%%%%%%%%%   %
%%%    %%%%%%%%%%%   %%%%%       %%%%%%%%%   %
%%    %%%%%%%%  %%   %%%%%%%%%%%%%%%%%  %%   %
%        %%%%%%     %%%%%%%%%%%%%%%%%%%     %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN FORBIDDEN
*/
