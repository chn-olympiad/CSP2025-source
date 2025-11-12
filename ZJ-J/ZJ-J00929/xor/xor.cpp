#include<bits/stdc++.h>
using namespace std;
long long k;
int n,a[100005],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int c=a[i];
			for(int q=i+1;q<=j;q++){
				if(a[q]==-1){
					c=k-1;
					break;
				}
				c^=a[q];
			}
			if(c==k){
				ans++;
				for(int w=i;w<=j;w++){
					a[w]=-1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
