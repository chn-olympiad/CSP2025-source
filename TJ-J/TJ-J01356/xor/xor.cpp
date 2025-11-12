#include<bits/stdc++.h>
using namespace std;

#define int long long

bool cmp(vector<int> x, vector<int> y){
	return x[1]<y[1];
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin>>n>>k;
	vector<int> v;
	for(int i = 0 ; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int sum;
	vector<vector<int> > choice;
	for(int i = 0; i<n; i++){
		sum = 0;
		for(int j = i; j<n; j++){
			sum^=v[j];
			if(sum == k){
				vector<int> t;
				t.push_back(i);
				t.push_back(j);
				choice.push_back(t);
			}
		}
	}
	sort(choice.begin(),choice.end(),cmp);
	int result;
	if(choice.empty()){
		result = 0;
	}else{
		result = 1;
		int previous = choice[0][1];
		for(int i = 1; i<choice.size(); i++){
			if(choice[i][0]>previous){
				result++;
				previous = choice[i][1];
			}
		}
	}
	cout<<result;
	return 0;
}

