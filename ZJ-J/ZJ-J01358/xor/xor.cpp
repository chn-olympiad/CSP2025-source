#include<bits/stdc++.h>
using namespace std;
int n,m,s,tss,x,op,num,ans,pmpm,a[500005];
bool b[500005];
int c[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=0;k<n;k++){
		for(int l=1;l<=n-k;l++){
			int t=0;
			memset(c,0,sizeof(c));
			for(int i=l;i<=l+k;i++){
				if(b[i]==1){
					t=1;
					break;
				} 
				tss=1;	
				op=a[i];	
				while(op!=0){
					x=op>>1;
					if(c[21-tss]!=op-(x<<1)) c[21-tss]=1;
					else c[21-tss]=0;
					tss++;
					op=x;
				}
			}
			if(t) continue;
			ans=1;
			num=0;
			for(int j=20;j>=0;j--){
				num+=ans*c[j];
				ans=ans<<1;
			}
			if(num==s){
				pmpm++;
				for(int i=l;i<=l+k;i++) b[i]=1;
			}
		}
	}
	cout<<pmpm;
	return 0;
}
