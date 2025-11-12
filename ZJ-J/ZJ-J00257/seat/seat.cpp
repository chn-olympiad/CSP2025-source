#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],k,w,q;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>s[i];
	k = s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++) {
		if(s[i] == k){
			w = i;
			break;
		}
	}
	if(w%n==0){
		cout<<w/n<<' ';
		q = w/n;
	} else {
		cout<<w/n+1<<' ';
		q = w/n+1;
	}
	if(q%2 == 1){
		if(w%n==0){
			cout<<n;
		}
		else {
			cout<<w%n;
		}
	} else {
		if(w%n==0){
			cout<<1;
		}
		else {
			cout<<n-w%n+1;
		}
	}
	return 0;
}
