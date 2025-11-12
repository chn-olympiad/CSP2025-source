#include <bits/stdc++.h>
using namespace std;
int a[6000];
int t1[6000];
int idx1=0; 
int to2(int num){
	memset(t1,0,sizeof(t1));
	idx1=0;
	if(num==0){
	    idx1=1;
	    memset(t1,0,sizeof(t1));
	} 
	while(num>0){
		idx1++;
		t1[idx1]=num%2;
		num/=2;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int len=3;
	int new_n=1;
	for(int i=1;i<=n;i++){
		new_n*=2;
	} 
	for(int i=1;i<=new_n;i++){
		int cnt=0;
		long long sum=0,Max=-1;
		to2(i);
		for(int j=1;j<=n;j++){
			if(t1[j]==1){
				cnt++;
				sum+=a[j];
				if(a[j]>Max){
					Max=a[j];
				}
			}
		}
		if(cnt>=3){
			if(sum>Max*2){
				ans++;
				for(int j=1;j<=n;j++){
					cout<<t1[j];
				}
				cout<<endl;
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
