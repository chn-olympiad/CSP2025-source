#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int h[105];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int nh,nl;
	cin>>nh>>nl;
	for(int i=1;i<=nh*nl;++i)
		cin>>h[i];
	int r=h[1];
	sort(h+1,h+nh*nl+1,greater<int>());
	/*
	for(int i=1;i<=nh*nl;++i)
		cout<<h[i]<<' ';
	cout<<endl;
	*/
	for(int i=1;i<=nh*nl;++i)
		if(h[i]==r){
			int l=(i-1)/nh+1,h;
			if(l&1)
				h=i-(l-1)*nh;
			else
				h=nh*l-i+1;
			cout<<l<<' '<<h;
			return 0;
		}
	return 0;
}
/*
2 2
99 97 98 100
*/
/*
2 2
98 99 100 97
*/
/*
4 3
120 1 2 3 4 5 6 99 102 103 108  150
*/
