#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int rd(){
	int f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	int x=(c&15);while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c&15);
	return x*f;
};
int a[N],x[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=rd(),k=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),x[i]=x[i-1]^a[i];
	for(int i=1;i<=n;i++){
		int fl=0,j=i;
		if(a[i]==k)fl=true;
		else {
			for(j=i+1;j<=n;j++){
				if((x[j]^x[i-1])==k){fl=true;break;}
			}
		}
		if(fl){
			i=j;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
