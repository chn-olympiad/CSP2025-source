#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	vector<int>xored(n+1,0);
	vector<vector<int>>xor_map;
	unordered_map<int,int>um;
	
	vector<int>p;
	xor_map.push_back(p); 
	int sum=0,chip=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		xored[i]=xored[i-1]^a[i];
		if(um[xored[i]]==0){
			um[xored[i]]=++chip;
			vector<int>p;
			p.push_back(i);
			xor_map.push_back(p);
		}
		else{
			xor_map[um[xored[i]]].push_back(i);
		}
	}
	
	
	
	int more_right=0;
	for(int l=1;l<=n;l++){
		int should_r=k^xored[l-1];

		if(um[should_r]==0) {
			continue;		
		}
		else{
			
			for(int i=0;i<xor_map[um[should_r]].size();i++){
				
				int new_r=xor_map[um[should_r]][i];
				
				if(new_r<l) continue;
				else {
					l=new_r;
					sum++;
					break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
/*

*/ 
