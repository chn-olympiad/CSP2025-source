#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans=1;
struct node{
	int L,R;
}p[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int l=1;l<=n;++l){
		for(int r=1;r<=n;++r){
			int sum=a[l];
			for(int i=l;i<r;++i){
				sum=sum xor a[i+1]; 
			}
//			cout<<sum<<endl;
			if(sum==k){
				p[ans++].L=l;
				p[ans-1].R=r;
			}	
		}
	}
	int t=ans;
	for(int i=1;i<ans;++i)
		for(int j=1;j<ans;++j){
			if(i!=j&&p[i].L<=p[j].R)
				--t;
				if(p[i].R-p[i].L<p[j].R-p[j].L){
					p[j].L=1e9;
					p[j].R=-1e9;
				}
		}
	cout<<t;
	return 0;
}

