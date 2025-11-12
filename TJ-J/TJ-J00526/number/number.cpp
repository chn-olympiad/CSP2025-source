#include<bits/stdc++.h>
using namespace std;
long long shu[1000000]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s,cnt=1,cnt0=0;
	cin>>s;
	if(s==0){
		cout<<0;
		return 0;
	}
	while(s>0){
	    if(s/cnt%10>0 && s/cnt%10<=9){
			shu[s/cnt%10]++;
			s=s-s/cnt%10*cnt;
		}else if(s/cnt%10==0){
			cnt0++;
			s=s-s/cnt%10*cnt;
		}
		cnt*=10;
	}
	for(int i=1000000;i>=0;i--){
		for(int j=0;j<shu[i];j++){
			cout<<i;
		}
	}
	if(cnt0>0){
		for(int i=1;i<=cnt0;i++){
			cout<<0;
		}
	}
} 
