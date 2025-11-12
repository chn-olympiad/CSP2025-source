/*=====club.cpp=====*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		int n; 
		cin>>n;
		int a[3][n];
		int wm = n/2;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
			    cin>>a[j][i];
		    }
		}
		long long m = 0;
		long long max = 0;
		cout<<max;
	}
	return 0;
}
