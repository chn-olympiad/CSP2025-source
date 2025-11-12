#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0;
int c[505],d[505];
string s;

bool cnt[505];
int as[505];

void f(int N){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	if(N==n+1){
		int cnt1=0,ans1=0;
		for(int i=1;i<=n;i++){
			//cout<<as[i]<<' ';
			int p=cnt1;
			if(p>=c[as[i]]||d[i]==0){
				cnt1++;
				continue;
			}
			else{
				ans1++;
			}
		}
		//cout<<endl;
		if(ans1>=m)ans++;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(cnt[i])continue;
		else{
			cnt[i]=1;
			as[N]=i;
			f(N+1);
			as[N]=0;
			cnt[i]=0;
		}
	}
	
}

int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		d[i+1]=s[i]-'0';
	}
	f(1);
	cout<<ans<<endl;
}
