#include<bits/stdc++.h>
using namespace std;
int n,m;
int v;
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	cin>>v;
	for(int i=1;i<p;i++){
		int q;
		cin>>q;
		if(q>v){
			cnt++;
		}
	}
	int cnt1=cnt/n;
	int cnt2=cnt%n;
	if(cnt2>0)cnt1++;
	else cnt2=n;
	if(cnt1%2==1){
		cout<<cnt1<<" "<<cnt2;
	}
	else{
		cout<<cnt1<<" "<<n-cnt2+1;
	}
	return 0;
}
