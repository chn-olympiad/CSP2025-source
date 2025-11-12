#include <bits/stdc++.h>
using namespace std;
bool cmp(int a[], int b[]){
	return a[0]<b[0];
}
bool has_all_cities(const vector<int>& a, int n){
	bool o = true;
	for(int i=1;i<=n;i++){
		o = o&&(find(a.begin(), a.end(), i)!=a.end());
	}
	return o;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	int weighed[n+k+1][n+k+1];
	for(int i=0;i<n+k+1;i++){
		for(int j=0;j<n+k+1;j++){
			weighed[i][j]=INT_MAX;
		}
	}
	int roads[m][3] = {};
	int villages[k][n+1] = {};
	for(int i=0;i<m;i++){
		scanf("%d %d %d", &roads[i][0], &roads[i][1], &roads[i][2]);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d", &villages[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		weighed[roads[i][0]][roads[i][1]]=roads[i][2];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			weighed[n+i+1][j+1]=villages[i][j+1]+villages[i][0];
		}
	}
	vector<int> connected;
	int o=0;
	while(1){
		int tmp[n+k][3] = {};
		for(int i=1;i<=n+k;i++){
			auto __min = min_element(weighed[i], weighed[i]+n+k);
			tmp[i-1][0] = *__min;
			tmp[i-1][1] = i;
			tmp[i-1][2] = __min-weighed[i];
		}
		auto __min_ = min_element(tmp, tmp+n+k, cmp);
		if(find(connected.begin(), connected.end(), (*__min_)[1])!=connected.end()&&find(connected.begin(), connected.end(), (*__min_)[2])!=connected.end()){
			weighed[(*__min_)[1]][(*__min_)[2]]=INT_MAX;
			continue;
		}
		weighed[(*__min_)[1]][(*__min_)[2]]=INT_MAX;
		connected.push_back((*__min_)[1]);
		connected.push_back((*__min_)[2]);
		o+=(*__min_)[0];
		sort(connected.begin(), connected.end());
		if (unique(connected.begin(), connected.end())-connected.begin()>=n&&has_all_cities(connected, n)) break;
	}
	cout<<o-1<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}