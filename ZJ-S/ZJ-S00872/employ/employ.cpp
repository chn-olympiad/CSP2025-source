#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int a[100100],b[100100],c[100100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
	sort(a+1,a+n+1);
	do{
		for(int i=1;i<=n;i++){
			c[i]=a[b[i]];
		}
		int cnt=0,cnt1=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cnt++;
			}else{
				if(cnt>=c[i+1]){
					cnt++;
				}else{
					cnt1++;
				}
			}
		}
		
		if(cnt1>=m){
			ans++;
		}
	}while(next_permutation(b+1,b+n+1));
	cout<<ans;
	return 0;
}