#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,ct=0,c[510];
bool dete[20];
long long ans;
char st[510];

void work(int t,int gu,int em){
	if(gu-em>ct)return;
	if(t==n&&em>=m){
		ans++;
		ans%=p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!dete[i]){
			dete[i]=1;
			if(st[t]=='0'||gu>=c[i]){
				work(t+1,gu+1,em);
			}
			else{
				work(t+1,gu,em+1);
			}
			dete[i]=0;	
		}
	}
	
	
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	
	if(n<=100){
		sort(c+1,c+n+1);
		ct=c[n-m];
		for(int i=1;i<=n;i++){
			dete[i]=1;
			if(st[0]=='0'||0>=c[i]){
				work(1,1,0);
			}
			else{
				work(1,0,1);
			}
			dete[i]=0;
			
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}

	return 0;
}


