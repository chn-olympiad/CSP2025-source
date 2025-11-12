#include<bits/stdc++.h>
using namespace std;
int n;
long long k1;
int a[500005];
struct node{
	int l,r;
}b[500005];
bool qwer(int w,int l,int r){
	bool flag=true;
	for(int i=0;i<=w;i++){
		if(r<=b[i].l||l>=b[i].r){
			
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out ","w",stdout);
	cin>>n>>k1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=0,ans=0,c=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i+1;k<=j;k++){
				c=a[k-1]^a[k];
			}
			if(c==k1&&qwer(w,i,j)){
				ans++;
				b[w].l=i;
				b[w].r=j;
				w++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
