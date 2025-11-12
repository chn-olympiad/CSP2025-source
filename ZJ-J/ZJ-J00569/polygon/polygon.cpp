#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int summ[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		summ[i]=summ[i-1]+a[i];
	}
	sort(a+1, a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		int cnt=0;
		for(int i=3; i<=n; i++){
			//cout<<summ[i-1]<<" "<<a[i]<<endl;
			if(summ[i-1]>a[i]){
				cnt++;
				//cout<<"y"<<endl;
			}
			for(int j=1; j<i; j++){
				for(int k=j; k<i; k++){
					//cout<<summ[i-1]-(summ[k]-summ[j-1])<<" "<<a[i]<<endl;
					if(summ[i-1]-(summ[k]-summ[j-1])>a[i]){
						cnt++;
						cnt%=998;
						cnt%=244;
						cnt%=353;
						//cout<<"y"<<endl;
					}else{
						break;
					}
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
