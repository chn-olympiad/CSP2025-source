#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int cost_least = 0;
int a[3] = {1,2,3};
struct N{
	int st;
	int ed;
	int my;
};
int n, m ,k;
N r[1000005];
int mo[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> r[i].st >> r[i].ed >> r[i].my;
		mo[i] = r[i].my;
	}
	sort(mo + 1,mo+m + 1);
//	sort(a, a + 3);
	//cout << a[0] << a[1] << a[2];
	for(int i = 1; i < n; i++){
		cost_least += mo[i];
		//cout << mo[i] << endl;
	}
	cout << cost_least;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
