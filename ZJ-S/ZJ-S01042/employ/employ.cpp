#include <bits/stdc++.h>

using namespace std;

int test[505];
int st[505];
bool vis[505];
int n,m,answer=0;
//int diff[505];
string s;
int tester(){
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			cnt++;
		}
		else{
			if(st[i]>cnt){
				ans++;	
//				cout<<ans<<"f   "<<endl;
			}
			else{
				cnt++;
			}
		}
	}
//	cout<<"-ans- "<<ans<<endl;
	return ans;
}

void srt(int d){
	if(d==n+1){
//		cout<<endl<<endl;
		int a = tester();
//		cout<<"-a- "<<a<<endl;
		if(a>=m){
			answer++;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			st[d]=test[i];
//			cout<<st[d]<<' ';
			srt(d+1);
			vis[i]=0;		
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;

	for(int i=1;i<=n;i++){
		cin>>test[i];
	}
	srt(1);
	cout<<answer;
	return 0;
}

