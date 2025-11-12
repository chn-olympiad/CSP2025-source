#include<bits/stdc++.h>
using namespace std;
int a[500050];
int n, k;
int ans;
//int xon(int s, int e, int k){
//	if(s == e && a[s] == k)return 1;
//	if(s >= e)return 0;
//	int rans = 0;
//	int sum = a[s];
//	bool ixn = 0;
//	for(int i = s; i<= e; i++){
//		if(sum == k){
//			rans += xon(s + 1, e, k);
//			sum = a[i + 1];
//			ixn = 1;
//		}
//		else sum = sum ^ a[i];
//	}
//	if(!ixn)return 0;
//	return rans;
//}
int xon(int s, int e, int k){
	if(s == e && a[s] == k)return 1;
	if(s >= e)return 0;
	int rans = 0;
	int sum = 0;
	bool ixn = 0;
	for(int j = s; j<= e; j++){
		sum = 0;
		for(int i = j; i<= e; i++){
			ixn = 0;
		    if(sum == k){
		    	rans += xon(j, i - 1, k);
		    	sum = a[i + 1];
		    	ixn = 1;
		    }
		    else sum = sum ^ a[i];
	    }
	    if(sum == k && ixn == 0){
		    rans += xon(j, e - 1, k);
		    ixn = 1;
		}
	}
	
	if(rans == 0)return 1;
	return rans;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>k;
	for(int i = 1; i<= n; i++){
		cin>>a[i];
	}
	cout<<xon(1, n, k);
	return 0;
}