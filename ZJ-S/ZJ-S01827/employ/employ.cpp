#include<bits/stdc++.h>
using namespace std;
int n,m;
char s;
int c[100001];
int ans,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=='1') cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<(1<<n);i++){
		int num=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) num++;
		}
		if(num!=cnt) continue;
		num=0;
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0){
				num++;
			}
			else{
				if(num>=c[i]) num++;
			}
		}
		if(num>=m) ans++;
	}
	cout<<ans;
	return 0;
}

