#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l;
    bool isa=1;
    vector<int> a;
    cin>>n>>k;
    for(int i = 0; i<n; i++){
    	cin>>l;
    	if(l!=1) isa = 0;
    	a.push_back(l);
	}
	if(k==0&&isa==1)cout<<n/2;
	else{
		if(k==1){
			int cnt = 0;
			for(int i = 0; i<n; i++){
				if(a[i]==1)cnt++; 
				}
			cout<<cnt;
			}
		else if(k==0){
			int cnt = 0;
			for(int i = 0; i<n; i++){
				if(a[i]==0)cnt++; 
				if(i>0&&a[i]==1&&a[i-1]==1)cnt++;
				}
			
			cout<<cnt;
		}
		}
	
    return 0;
}

