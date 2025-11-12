#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],m,m_=INT_MAX;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		m=max(m,a[i]);
		m_=min(m_,a[i]);
	}
	if(m==1&&m_==1&&!k)cout<<n/2;
	else if(m==1&&!m_){
		if(k){
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			int cnt = 0,n1=0;
            for(int i = 1;i <= n;i++){
				if(a[i]==0)cnt++,n1=0;
				else if(n1)cnt++,n1=0;
				else n1++;
			}
			cout<<cnt; 
		}
	}else{
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[i]==k)cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
