#include<bits/stdc++.h>
using namespace std;
int n,m,c[10000],ans,flag,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			cnt++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=1){
			flag=1;
		}
	}
	if(flag=0){
		while(1){
			n--;
			ans=ans*n;
			if(n==1){
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		while(1){
			cnt--;
			ans=ans*cnt;
			if(cnt==1){
				break;
			}
		}
		
	}
	if(m==n){
		cout<<1;
		return 0;
	}
	return 0;
}

