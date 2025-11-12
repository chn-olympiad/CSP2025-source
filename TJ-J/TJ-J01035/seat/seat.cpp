#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mp[1000][1000],a[1000],b[1000];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int qi = 1;qi<=n*m;qi++){
		cin >> a[qi];
		b[qi] = a[qi];
	}
	sort(&a[1],&a[n*m+1],cmp);
	int i = 1,j = 1,flag = 0,y = 1;
	for(int z = 1;z<=n*m;z++){
		mp[i][j] = a[z];
		if(i == n && flag == 0){
			j++;
			flag = 1;
		}else if(i == 1 && flag == 1){
			j++;
			flag = 0;
		}else{
			if(flag) i--;
			else i++;
		}
	}	
	for(int _i = 1;_i<=n;_i++){
		for(int _j = 1;_j<=m;_j++){
			if(mp[_i][_j] == b[1]){
				cout << _j << " " << _i;
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
