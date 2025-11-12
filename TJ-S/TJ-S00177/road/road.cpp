#include<bits/stdc++.h> 
using namespace std;
int n,m,k,res=0;
int arr[100005][3],arrr[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for(int i=1;i<=k;i++){
		cin >> arrr[i];
		res+=arrr[i];
	}
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
