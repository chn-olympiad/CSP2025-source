#include<bits/stdc++.h>
using namespace std;

int n,m;//面试的，录取的 
char s[505];//难度 
int c[505];//耐心 
int cnt,ans;//放弃的 ,最终答案 

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	
	for(int i=1;i<=n;i++){
		if(s[i]=='0'&&c[i]>cnt) ans++;
		else cnt++;
	}
	
	cout<<ans<<endl;
	return 0;
}
