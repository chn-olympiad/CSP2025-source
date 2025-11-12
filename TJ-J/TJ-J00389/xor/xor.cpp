#include<bits/stdc++.h>
using namespace std;
const int mx=50e5+5;
// 
int n,k,t,ans;


struct nd{
	int val;
	int used;
};
nd a[mx];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >>n>>k;
	for(int i=0;i<n;i++){
		cin >>a[i].val;
		a[i].used = 0;
		if(a[i].val!=1) t=1;	
	}
	if(!t&&k==0) cout <<n/2;
	else if(k==0){
		for(int i=0;i<n-1;i++){
			if(a[i].used!=1&&a[i+1].used!=1&&a[i].val==a[i+1].val){
				ans++;
				a[i].used++;
				a[i+1].used++;
			}
		}
	}else{
		for(int i=0;i<n-1;i++){
			if(a[i].used!=1&&a[i+1].used!=1&&a[i].val!=a[i+1].val){
				ans++;
				a[i].used++;
				a[i+1].used++;
			}
		}
	}
	
	cout <<ans;
	return 0;
}
