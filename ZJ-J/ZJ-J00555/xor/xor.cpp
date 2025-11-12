#include<bits/stdc++.h>
using namespace std;
int n;
int t[2100000];
int k;
int a[500010];
int ans=0;
int l,q=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q<=n){
		q=l+1;
		t[0]=1;
		int xorn=0;
		for(;q<=n;q++){
			xorn^=a[q];
			if(t[k^xorn]){
				int newxorn=0;
				for(int j=l+1;j<q;j++){
					newxorn^=a[j];
					t[newxorn]=0; 
				}
				l=q;
				ans++;
				break;
			}
			t[xorn]=1;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

