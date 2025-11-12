#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],d1=1;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int l = n * m;
	for(int i = 1; i <= l; i++)
		cin >> a[i];
	int r = a[1];
	sort(a + 1, a + l + 1, cmp);
	int lie = 1,hang = 1;
	for(int i = 1; i <= l; i++)
	{
		if(a[i] == r){
			cout << lie << " " << hang;
			break;
		}
		if(hang == 1&& d1 != 1){
			lie += 1;
			d1 = 1;
		}else
		if(hang == n && d1 != -1){
			lie += 1;
			d1 = -1;
		}else
			hang += d1;
	}
	return 0;
}
