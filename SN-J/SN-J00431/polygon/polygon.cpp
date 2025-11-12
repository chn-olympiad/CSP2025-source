#include <bits/stdc++.h>
using namespace std;
int N, C;
bool b=true;
vector<int> v;
bool cmp(int a, int b){
	if(a>b) return true;
	else if(b>=a) return false;
}
int main(){
	freopen("polyon.in", "r", stdin);
	freopen("polyon.out","w",stdout);
	cin>>N;
	for(int i=0; i<N; i++){
		int k; cin>>k;
		if(k != 1) b=false; 
		v.push_back(k);
	}
	sort(v.begin(), v.end(), cmp);
	if(N == 3){
		if(v[0]<v[1]+v[2]){
			cout<<1;
			return 0;
		}
	}
	if(b){
		cout<<N-2;
		return 0;
	} 
}
