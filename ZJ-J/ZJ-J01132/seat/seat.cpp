#include<bits/stdc++.h>
using namespace std;
int s[20][20],cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	int a;
	cin>>a;
	for(int i=1;i<l;i++){
		int x;
		cin>>x;
		if(x>a)cnt++;
	}
	int ansm=cnt/n+1,ansn=0;
	if(ansm%2==0){
		ansn=n-cnt%n;
	}else if(ansm%2!=0){
		ansn=cnt%n+1;
	}
	cout<<ansm<<' '<<ansn;
	return 0;
}