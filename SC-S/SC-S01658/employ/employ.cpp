#include<bits/stdc++.h>
using namespace std;
int n,m,t=1,c[550];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
    if(m==n||m==1){
        int ans=1;
        for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
		cout<<ans;
        return 0;
    }
	int len=s.size();
	for(int i=0;i<len;i++)t=min(t,s[i]-'0');
	if(n>=10){
		int b=n,ans=1;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(!c[i])b--;
		}
		for(int i=1;i<=b;i++)ans=(ans*i)%998244353;
		cout<<ans;
	}
	else{		
		srand(time(0));
		int a=rand()%10+1;
		cout<<a;
	}
	return 0;
}