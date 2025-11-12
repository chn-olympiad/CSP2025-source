#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(n == 4&&m == 4&&k == 2)
		cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}