#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n;
int a[100];
char s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	return 0;
}
/*
TCS has only 1 ball.
Loop1st has only 1 ball.
WinterXorSnor has only 1 ball.
ONLY Concert_B has 2 balls.









































*/
