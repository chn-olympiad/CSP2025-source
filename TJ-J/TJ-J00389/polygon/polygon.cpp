#include<bits/stdc++.h>
using namespace std;

//1.找到s根木棍（s>=3&&s<=n) 
//2.按照条件计算、结果取余 
//3. 

int n;
int sk[5005],mx=-1;
int used[5005];
long long c,ans;
bool only1=true;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin >>sk[i];
		if(sk[i]!=1) only1 = false;
	}
	if(n==3){
	for(int i=0;i<n;i++){
		c+=sk[i];
		mx = sk[i]>mx?sk[i]:mx;
	}
	if(c>mx*2) ans++;
	}
	else if(only1){
		ans = n/3;
	}
	
	
	cout <<ans;
	/*
	for(int i=0;i<=n-3;i++){
		int no[i]
		for(int j=0;j<i;j++){
			no[j] = 
	
	*/
	
	return 0;
}
