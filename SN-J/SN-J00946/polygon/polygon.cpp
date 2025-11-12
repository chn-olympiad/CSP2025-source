#include <bits/stdc++.h>
using namespace std;
int high[5005], choice[5005], havec[5005];
int n, mxh, ans, pos;
vector <int> schoice;
bool cmp(int x, int y){
	return x>y;
}
bool canc(int l){
	int schoice[pos+5], alth = 0;
	memset(schoice,0,pos+5);
	for (int j=0; j<pos; j++){
		schoice[j] = choice[j];
	}
	schoice[pos] = l;
	sort(schoice,schoice+pos,cmp);
	for (int j=1; j<pos; j++){
		alth += schoice[j];
	}
	if (alth <= schoice[0]) return false;
	return true;
}
void dfs(int h){
	if (h > n) return;
	for (int i=0; i<n; i++){
		if ((!havec[i] && canc(high[i])) || h<3){
			havec[i] = 1;
			choice[pos++] = high[i];
			ans ++;
			ans %= 998244353;
			dfs(h+1);
			havec[i] = 0;
			choice[--pos] = 0;
		}
	}
	return;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> high[i];
	}
	sort(high,high+n);
	dfs(1);
	cout << ans%998244353 << endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
