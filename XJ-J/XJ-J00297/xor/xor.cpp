#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

void IOP(){
	cin.tie(0) ,cout.tie(0);
	ios::sync_with_stdio(0);
}

void frop(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}

const int N = 2e5+5;
int n,k;
bool a[N];

int main(){
	frop();//必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 
	IOP();//注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	int cnt = 0;
	for(int i=1;i<=n;i++)cnt+=a[i]==1;
	
	
	if(k==0){
		if(n<=2){
			if(n==0)cout<<0;
			if(n==1)cout<<a[1]==0;
			if(n==2)cout<<(a[1]==a[2]);
			return 0;
		}
		
		bool fst=0,lst=0;
		int st=0,ed=0,ans=0;
		for(int i=1;i<=n;i++){
			if(!fst){
				if(a[i]==1)fst=1,st=i;
			}else{
				if(a[i]==1)lst=1,ed=i;
				ans+=ed-st;
			}
		}
		
		cout<<ans;
		
	}else if(k==1){
		
		cout<<cnt;
	}
	
	return 0;
}
