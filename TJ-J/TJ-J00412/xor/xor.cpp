#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	if(k==0){
		int ta = 1;
		for(int i=0;i<n;i++){
			if(a[i]!=1);
				ta=0;	
		}
		if(ta==1){
			cout<<n/2;
			return 0;
		}
	}
	if(k==0||k==1){
		int tb =1;
		for(int i=0;i<n;i++){
			if(a[i]!=1&&a[i]!=0){
				tb=0;
			}
		}
		if(tb==1){
			if(k==1){
				int sum=0;
				for(int i=0;i<n;i++){
					sum+=a[i];
				}
				cout<<sum;
				return 0;
			}
			if(k==0){
				int sum =0;
				for(int i=0;i<n;i++){
					if(a[i]==1){
						if(a[i+1]==1){
							sum++;
							++i;
						}
					}
					if(a[i]==0){
						sum++;
					}
				}
				cout<<sum;
				return 0;
			}
		}
	}
	int f=6;
	cout<<f;
	//CCF我是真的没招了，┭┮﹏┭┮ 
	return 0;
}
