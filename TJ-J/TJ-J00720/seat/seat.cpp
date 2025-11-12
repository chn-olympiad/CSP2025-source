#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int n,m,s[150],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	rep(i,1,n*m) cin>>s[i];
	rep(i,1,n*m) rep(j,1,n*m){
		if(j==1) continue;
		if(s[j]<s[j+1]) swap(s[j],s[j+1]);
	}
	int l=n*m;
	rep(i,2,l){
		if(s[1]>s[i]){
			l=i-1;
			break;
		}
	}
	if(l==0) l=n*m;
	rep(i,1,m){
		if(i%2==1){
			rep(j,1,n){
				l--;
				if(!l) cout<<i<<" "<<j;
			}
		}else{
			pre(j,n,1){
				l--;
				if(!l) cout<<i<<" "<<j;
			}
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

