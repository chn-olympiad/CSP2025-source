#include<bits/stdc++.h>
//好难，何意味 
using namespace std;


#define int long long
int a[5005];

const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("polygon4.in","r",stdin);
//	freopen("ans.out","w",stdout);
	int n;
	
	cin>>n;
	
	int ans=0;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=0;i<(1<<n);i++){
		int b=0,mx=0,s=0;
		
		int Q=i;
		for(int j=1;j<=n;j++){
			if(Q&1){
				b++;
				mx=max(mx,a[j]);
				
				s+=a[j];
			}
			Q>>=1;
		}
		
//		cout<<b<<" "<<mx<<" "<<s<<endl;
		
		if(b>=3){
			if(mx*2<s){
				ans++;
				ans%=mod;
			}
		}
	}
	
	cout<<ans<<endl;
}
/*
in:
5
1 2 3 4 5
out:
9
in:
5
2 2 3 8 10


太难了，完全不会

我太菜了

看到旁边小孩哥如云流水的切题

我还是太菜了

总分期望300pts 
*/
