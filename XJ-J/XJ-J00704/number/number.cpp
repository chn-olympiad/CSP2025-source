#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
long long num;
long long ans;
int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int sum;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			sum=s[i];
			cnt[sum]++;
			num++;
		}
	}
	for(int i=57;i>=48;i--){
		if(cnt[i]==0){
			continue;
		}else{
			for(int j=cnt[i];j>=1;j--){
				int a=i-48;
				long long b=1;
				for(int z=1;z<num;z++){
				b*=10;
				}
				ans+=a*b;
				num--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
