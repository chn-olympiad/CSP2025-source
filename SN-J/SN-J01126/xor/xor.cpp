#include <bits/stdc++.h>
using namespace std;
//"Are you sad?""Are you angry?"
//A youthful voice asked.
//"Don't be worried.I know all."
//The answer echoed in the sky.
//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
//probably yt on lg
//no,not completely same
int a[500005];
bool used[500005]; 
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >>n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	} 
	//10score passed tsxz A
//	cout << n/2;
	//30score passed tsxz B
	for(int i=1;i<=n;i++) {
		if(a[i]==k) {
			used[i]=1;
			ans++;
		} else if(used[i-1]==0&&((a[i]^a[i-1])==k)) {
			ans++;
			used[i]=1;
			used[i-1]=1;
		}
	}
	cout << ans;
	return 0;
} 
//WTF?!!!!! TEST THE BIT WHY?
//I gived up
