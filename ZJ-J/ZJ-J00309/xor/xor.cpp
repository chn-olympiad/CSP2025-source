#include<bits/stdc++.h>
using namespace std;
struct node{
	int z;
	int y;
};
node w[5000005];
int n,k,a[500005],f[500005],t=0,x,ans=0,s;
bool cmp(node b,node c){
	if(b.y<c.y) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==k){
    		t++;
    		w[t].z=i;
    		w[t].y=i;
		}
    	f[i]=f[i-1]^a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
		    s=f[i]^f[j];
			if(s==k){
				t++;
				w[t].z=i+1;
				w[t].y=j;
			}
		}
	}
	if(t==0){
		cout<<0;
		return 0;
	}
	sort(w+1,w+1+t,cmp);
	x=w[1].y;
	for(int i=2;i<=t;i++){
		if(w[i].z>x){
			ans++;
			x=w[i].y;
		}
	}
	cout<<ans+1;
	return 0;
}
