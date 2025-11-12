#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	long long k;
	cin>>n>>k;
	long long a[n+3];
	int flag = 1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag = 0;
		}
	}
	int cnt=0;
	if(k==0 && flag){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		int s = 0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cnt++;
				s=0;
			}
			else if(a[i]==1){
				s++;
			}
			if(s%2==0&&s!=0){
				cnt++;
				s=0;
			}
		}
		cout<<cnt;
	}
	else if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
