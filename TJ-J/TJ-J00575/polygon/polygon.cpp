#include<bits/stdc++.h>
using namespace std;
vector<bool> bn;
int n;
vector<int> wdl;
long amod = 998244353;
bool can(){
	int ls = 0;
	int sm = 0;
	int mx = 0;
	for(int i = 0;i < n;i++){
		if(bn[i]){
			ls++;
			sm += wdl[i];
			mx = max(mx,wdl[i]);
		}
	}
	if(ls <= 2){
		return false;
	}
	//cout << sm << " " << mx << endl;
	if(sm > mx*2){
		return true;
	}else{
		return false;
	}
}
int k = 0;
int df(int m){
	if(wdl.size() == m-1){
		int hj = 0;
		for(int i = 0;i < n;i++){
			if(bn[i]){
				hj++;
			}
		}
		if(hj <= 2){
			return 0;
		}
		bool h = can();
		if(h){
			k = k%amod + 1;
		}
		bn[m] = !bn[m];
		h = can();
		if(h){
			k = k%amod + 1;
		}
	}else{
		df(m+1);
		bn[m] = !bn[m];
		df(m+1);
	}
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i ++){
		int g;
		cin >> g;
		wdl.push_back(g);
		bn.push_back(false);
	}
	// 01 bag
	df(0);
	cout << k/4;
	return 0;
}
