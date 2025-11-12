#include<bits/stdc++.h>
using namespace std;

int a[500+10],jl[500+10];
bool t[500+10],hah[500+10];

int ans=0;
int n,m;
bool f=0;
void print(){
	if(f==0){
		ans++;
		ans%=998244353;
	}
	int num=0;
	for(int i=1; i<=n; i++){
		if(num>=a[jl[i]] || t[i]==0){
			num++;
		}
	}
	if(n-num>=m){
		ans++;
		ans%=998244353;
	}
}

void dfs(int k,int n){
	for(int i=1; i<=n; i++){
		if(hah[i]==0){
			jl[k]=i;
			hah[i]=1;
			
			if(k==n){
				print();
			}else{
				dfs(k+1,n);
			}
			
			jl[k]=0;
			hah[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	
	cin>>n>>m;
	
	char c[500+10];
	cin>>(c+1);
	for(int i=1; i<=n; i++){
		t[i]=c[i]-'0';
		if(t[i]==0) f=1; 
	}
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	dfs(1,n);
	
	cout<<ans;
	
	return 0;
}
