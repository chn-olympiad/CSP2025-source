#include <bits/stdc++.h>
using namespace std;
int sum[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	int len=a.size(),cnt=1;
	for(int i=0;i<=len-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			sum[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(sum+1,sum+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<sum[i];
	}
	return 0;
} 
