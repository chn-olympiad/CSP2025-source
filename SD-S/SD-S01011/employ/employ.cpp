#include<bits/stdc++.h>
using namespace std;
long long int p[1000];
long long int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		p[c]++;
	}
	for(int i=n-1;i>=0;i--){
		p[i]+=p[i+1];
		//cout<<p[i]<<endl;
	}
	int c=0;
	int l=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){	
			c++;
		}
	}
	long long int ans=1;
	for(int i=n-1;i>=0;i--){
		l++;
		if(s[i]=='1' || i==0){
			long long int y=1;
			//cout<<p[c]<<endl;
			for(int j=0;j<l;j++){
				y=(y*(p[c]-j))%mod;
			}
			c--;
			p[c]-=l;
			l=0;
			//cout<<y<<endl;
			if(y==0) continue;
			ans=(ans*y)%mod; 
		}
	}
	cout<<ans;
	return 0;
} 
