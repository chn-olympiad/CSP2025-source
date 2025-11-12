#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,k;
	set<int>s;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>k;
			s.insert(k);
			if (i==0&&j==0) a=k;
		}
	}
	set<int>::iterator iter=s.end();
	iter--;
	for (int i=1;;iter--,i++){
		if (*iter==a){
			int c=i/n,r=i%n;
			if (r==0&&c%2==1){
				cout<<c<<' '<<n;
			}else if (r==0&&c%2==0){
				cout<<c<<' '<<1;
			}else if ((c+1)%2==1){
				cout<<c+1<<' '<<r;
			}else{
				cout<<c+1<<' '<<n-r+1;
			}
			break;
		}
	}
	return 0;
}
