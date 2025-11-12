#include<bits/stdc++.h>
using namespace std;
int count0,count1;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) count1++;
		if(a[i]==0) count0++;
	}
	if(count1==n){
		if(k!=1||k!=0){
			cout<<0;
			return 0;
		}
		else{
			if(k){
				cout<<a.size();
				return 0;
			}
			else{
				if(a.size()%2){
					cout<<0;
				}
				cout<<a.size()/2;
			}
		}
	}
	if(count1+count0==a.size()){
		if(k!=1||k!=0){
			cout<<0;
			return 0;
		}
		if(count1%2==0&&count0%2==0){
			if(k==1){
				cout<<(count0+count1)/2;
				return 0;
			}
			if(!k){
				cout<<count0+count1/2;
				return 0;
			}
		}
		if(count0%2==0&&count1%2){
			if(count0>count1){
				if(!k){
					cout<<0;
					return 0;
				}
				else{
					cout<<count1;
					return 0;
				}
			}
			else{
				if(!k){
					cout<<0;
					return 0;
				}
				else{
					cout<<count1;
				}
			}
		}
	}
	return 0;
}
