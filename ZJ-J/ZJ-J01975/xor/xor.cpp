#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k,r,s=0,a[1000010],b[1000010],x,y;
int an[2010][2010],f[2010][2010];
long long xxor(long long x,long long y){
	if(x==0||y==0)return x+y;
	if(x<y)swap(x,y);
	if(f[x][y]!=0)return an[x][y];
	long long add=0;
	int o=1;
	
	while(x!=0||y!=0){
		c=x%2;
		r=y%2;
		
		if(c!=r)add+=o;
		o*=2;
	
		x>>=1,y>>=1;

	}f[x][y]=1,an[x][y]=add;
	return add;
}
void dfs(long long x,long long ans){
	if(x==n+1){
		s=max(s,ans);
		return ;
	}
	long long t=a[x];
	if(t==k){
			
			dfs(1+x,ans+1);
		}
	for(int i=x+1;i<=n;i++){
		t=xxor(a[i],t);
		if(t==k){
	
			dfs(1+i,ans+1);
		}
	}
	dfs(1+x,ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>k;
	s=-1;
	int fl=0;
	for(int i=1;i<=n;i++){	
	cin>>a[i];
	if(a[i]==0)fl=1;
	else if(a[i]>1)fl=2;

		}
	if(fl==0){
		if(k>=2){
				cout<<0;
				return 0;
			}
			if(k==1){
				cout<<n;
			return 0;
			}
			else if(k==0){
				cout<<n/2;
				return 0;
			}

	}
	else	if(fl==1){
			if(k>=2){
				cout<<0;
				return 0;
			}
			
			if(k==1){
				s=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1)s++;
				}cout<<s;
				return 0;	
			}
			if(k==0){
				s=0;int i=1;
				while(i<=n){
					if(a[i]==0)s++,i++;
					else if(a[i]==1&&a[i+1]==1)s++,i+=2;
					else i++;
				}
				cout<<s;
				return 0;	
			}
			
		}
	dfs(1,0);
	cout<<s;
	return 0;
}

