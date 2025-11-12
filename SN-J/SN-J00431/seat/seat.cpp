#include <bits/stdc++.h>
using namespace std;
int A[15][15];
int M, N;
vector<int> v;
bool cmp(int a, int b){
	if(a>b) return true;
	else if(b>=a) return false;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	int AD = N*M;
	int dir=2, r=1, c=1, i=1;
	while(AD--){
		A[r][c] = i;
		i++;
		if(dir == 1){
			r--;
			if(r < 1){
				dir = 2;
				c++;
				r++;
			} 
		}
		else if(dir == 2){
			r++;
			if(r > N){
				dir = 1;
				c++;
				r--;
			}
		}
	}
	int xiaor; cin>>xiaor;
	v.push_back(xiaor);
	for(int i=1; i<N*M; i++){
		int k; cin>>k;
		v.push_back(k);
	}
	sort(v.begin(), v.end(), cmp);
	int bookr;
	for(int i=0; i<v.size(); i++){
		if(v[i] == xiaor){
			bookr = i+1;
			break;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(A[i][j] == bookr){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
