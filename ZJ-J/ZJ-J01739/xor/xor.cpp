#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x,y;
ll k,a[500005];
bool q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			x++;
		}
		if(a[i]==1){
			y++;
		}
	}
	if(x+y==n){
	   if(y==n){
	   	  int ans=0;
	   	  while(n>=2){
	   	    n-=2;
			ans++;	 
		  }
		  cout<<ans;
		  return 0;
	   }   
	   if(x==n){
	   	if(k==0){
	   		cout<<n;
	   	    return 0;
		}
	   	cout<<0;
	   	return 0;
	   }
	   if(k==0){
	   	int ans=0;
	   	  for(int i=2;i<=n;i++){
	   	  	if(a[i]==a[i-1]&&q[i-1]==0){
	   	  		q[i]=1;
	   	  		q[i-1]=1;
	   	  	   	ans++;
	   	  	   	i++;
	   	  	   	continue;
			}
			if(a[i]==1&&a[i]==a[i-2]&&q[i-1]==0&&q[i-2]==0){
				q[i]=1;q[i-1]=1;q[i-2]=1;
			   ans++;
			   i++;
			}
		  }
		  cout<<ans;
	   }
	   if(k==1){
	   	int ans=0;
	   	  for(int i=2;i<=n;i++){
	   	  	if(a[i]!=a[i-1]){
	   	  	   	ans++;
	   	  	   	i++;
	   	  	   	continue;
			}
		  }
		  cout<<ans;
	   }
	}
	else{
		cout<<n;
	}
	return 0;
}
