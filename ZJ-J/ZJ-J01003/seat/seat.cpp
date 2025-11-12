#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e3+10;
i64 n, m;
i64 Arr[N];
i64 NeedSeat;
i64 PointSeat;
i64 c,r;
bool cmp(i64 a,i64 b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> Arr[i];
	}
	NeedSeat = Arr[1];
	sort(Arr+1,Arr+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (Arr[i] == NeedSeat){
			PointSeat = i - 1;
			break;
		}
	}
	/*
	cout << PointSeat <<endl;
	cout << ((PointSeat/n)+1) <<endl;
	cout << (PointSeat%m) <<endl;
	*/
	c = ((PointSeat/n)+1);
	if (c % 2 == 0){
		r = m - (PointSeat % m);
	}
	else{
		r = (PointSeat % m) + 1;
	}
	cout << c << " " << r <<endl;
	        
	fclose(stdin);
	fclose(stdout);
	return 0;
}