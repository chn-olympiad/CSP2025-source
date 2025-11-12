#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,cnt,sum=0;
	cin>>n>>m;
	int aaa[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>aaa[i];
		if(i==0){
			cnt=aaa[0];
		}
	}
	sort(aaa,aaa+n*m,cmp);
	for(int i=1,j=1;i<=n;i++){
		if(j<=1){
			while(j<=m){
				if(aaa[sum]==cnt){
					cout<<i<<' '<<j;
					return 0;
				}
				sum++;j++;
			}
		}
		else{
			while(j>1){
				j--;
				if(aaa[sum]==cnt){
					cout<<i<<' '<<j;
					return 0;
				}
				sum++;
			}
		}
		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}