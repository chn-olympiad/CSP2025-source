#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==1){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n,greater<int>());
		for(int i=0;i<n;i++){
			if(s[i]!='0'){
				if(a[0]>i){	
					long long mul=1;
					int last=0;
					for(int j=n-1;j>=0;j--){
						if(s[i]=='1'){
							int cnt=0;
							for(int k=last;k<n;k++){
								if(a[k]>j)cnt++;
								else{
									last=k;
									break;
								}
							}
							mul*=cnt;
							mul%=mod;
						}
					}
					cout<<mul;
				}
				else{
					cout<<0;
				}
				return 0;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt+=(x>0);
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	long long mul=1;
	for(int i=n;i>=1;i--){
		mul*=i;
		mul%=mod;
	}
	cout<<mul;
	return 0;
}
