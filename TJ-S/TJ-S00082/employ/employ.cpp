# include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000],a,sum=1,cnt=1;
string s;
bool f=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!=1){
			f=false;
		}
	}
	if(f==true){
		a=n;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				for(int j=1;j<=n;j++){
					if(j!=i&&c[j]<=1){
						cnt++;
					}
					if(n-cnt<m){
						a--;
					}
				}
			}	
		}
		for(int i=1;i<=a;i++){
			sum*=i;
			if(sum>=998244353){
				sum%=998244353;
			}
		}
		cout<<sum;	
	}
	else {
		cout<<1;
	}
	return 0;
}
