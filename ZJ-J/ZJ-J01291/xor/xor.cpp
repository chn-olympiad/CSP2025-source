#include<bits/stdc++.h>
using namespace std;
const int nn=1e5+10;
int a[nn],b[nn];
bool p=true;
int n,k,ans,minl;
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	youhua();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	minl=1;
	for(int i=1;i<=n;i++){
		p=false;
		for(int l=minl;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((b[r]^b[l-1])==k)
				{	
					if(p==false) minl=r+1;
					else minl=min(minl,r+1);
					p=true;
//					cout<<minl<<"\n";	
				}
			}
		}
		if(p==false) break;
		ans=i;
	}
	cout<<ans;
	return 0;
}

