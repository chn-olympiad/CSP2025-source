#include<bits/stdc++.h>
using namespace std;

const int N=5005;
const int MOD=998244353;
bool check[N];
int cnt[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=0;i<n;i++){
			
			int c;cin>>c;
			if(c==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	bool check_full=1;	
	for(int i=0;i<n;i++){
		if(s[i]=='0')check_full=0;
	}
	if(check_full){	
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			int c;cin>>c;
			cnt[c]++;
		}
		long long ans1=1;
		for(int i=0;i<n;i++){
			int temp=cnt[i];
			cnt[i]--;
			cnt[i+1]+=cnt[i];
			ans1%=MOD;
			ans1*=temp;
		}
		long long ans2=1;
		for(int i=n;i>0;i--){
			ans2*=i;
			ans2%=MOD;
		}
		cout<<(ans2-ans1+MOD)%MOD;
		return 0;
	}
	
	return 0;
}
