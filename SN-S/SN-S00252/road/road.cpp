#include<bits/sidc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin)
	freopen(".out","w",stdout)
	int a,m,k,n[1000000],b[1000000]c[1000100],maxn[10000020];
	cin>>a>>m>>k;
	for(int i;i<m;i++)
	    cin>>n[i]>>b[i]>>c[i];
    for(int i;i<b;i++)
    for(int v=i;v<b;v++)
        maxn[i]=c[i];
    if(n[i]==n[v]&&b[i]==b[v]||n[i]==b[v]&&n[v]==b[i]){
    	maxn[i]=c[v];
	}
      
	return 0;
}
