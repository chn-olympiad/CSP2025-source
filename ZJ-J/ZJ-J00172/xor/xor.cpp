#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,k,i,j,q,l,s,t,sb,mi,a[N],b[N],c[N],f[2000010];
struct no{
	int a,b;
}e[N];
bool cmp(no a,no b){
	return a.a<b.a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	
//	if(n<=1000){
//		for(i=1;i<=n;i++)b[i]=b[i-1]^a[i];
//		for(i=n;i>=1;i--)c[i]=c[i+1]^a[i];
//		for(i=1;i<=n;i++){
//			for(j=i;j<=n;j++)
//				if((b[j]^b[i-1])==k){
//					s++;mi=j;
//					for(q=i;q<=j;q++)
//						for(l=j;l>=q+2;l--)
//							if(((b[q] ^ b[i-1]) 
//							^ (c[l] ^ c[j+1]))==0)
//								mi=min(mi,l-1);
//					i=mi;
//					break;
//				}
//		}
//		cout<<s;
//	}
	
//	else{
		for(i=1;i<=n;i++)b[i]=b[i-1]^a[i];
		t=0;
		for(i=n;i>=0;i--){
//			cout<<i<<" "<<b[i]<<" "<<(k^b[i])<<" "<<f[(k^b[i])]<<"\n";
			if(f[(k^b[i])]!=0){
				e[++t]={i+1,f[(k^b[i])]};
			}
			f[b[i]]=i;
		}
		sort(e+1,e+1+t,cmp);s=1;sb=1;
//		for(i=1;i<=t;i++)cout<<e[i].a<<" "<<e[i].b<<"\n";
		for(i=2;i<=t;i++)
			if(e[i].a<=e[sb].b&&e[i].b<=e[sb].b)sb=i;
			else if(e[i].a>e[sb].b)s++,sb=i;
		cout<<s;
//	}
	
	return 0;
}
/*

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3


*/
