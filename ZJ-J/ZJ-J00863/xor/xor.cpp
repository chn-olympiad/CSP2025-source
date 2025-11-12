#include <bits/stdc++.h>
using namespace std;
int a[500004];
int c;
int l[5000003];
int r[5000003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u=a[i];
		int p=i;
		while(++p){
			if(u==m){
				//cout<<i<<" "<<p-1<<endl;
				l[++c]=i;
				r[c]=p-1;
				break;
			}
			if(p>n)break;
			u=u^a[p];
			
		}
	}
	int f=0;
	int s=0;
	
	for(int i=1;i<=c;i++){
		if(l[i]>f){
			f=r[i];
			int lll=i;
			for(int j=i+1;j<=c and l[j]<f;j++){
				if(r[j]<f){
					f=r[j];
					lll=j;
				}
			}
			s++;
		}
	}
	cout<<s;
}