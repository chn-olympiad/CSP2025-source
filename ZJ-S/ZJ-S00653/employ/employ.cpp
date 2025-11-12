#include <bits/stdc++.h>
using namespace std;
int n,m;
int flag,cnt,ff;
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch<'0'||ch>'1') ch=getchar();
		if(ch=='0') flag=1;
		if(ch=='1'&&cnt==0) cnt=i;
	}
	int c_cnt=0;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]==0) flag=1,ff++;
		if(c[i]>=cnt) c_cnt++;
	}
	if(n-ff<m){
		cout << 0;	
	}else if(m==1){
		if(cnt==0) cout << 0;
		else{
			long long sum=1;
			for(int i=2;i<=n;i++){
				sum*=i;
				sum%=998244353;
			}
			if(c_cnt>=cnt){
				cout << sum;
			}else{
				long long sum1=1,sum2=1;
				for(int i=cnt-1;i>=cnt-c_cnt;i--){
					sum1*=i;
					sum1%=998244353;
				}
				for(int i=2;i<=n-c_cnt;i++){
					sum2*=i;
					sum2%=998244353;
				}
				long long ss=sum1*sum2%998244353;
				cout << (sum-ss+998244353)%998244353;
			}
		}
	}else if(m==n&&flag){
		cout << 0;
	}else{
		long long sum=1;
		for(int i=2;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout << sum;
	}
	return 0;
}
