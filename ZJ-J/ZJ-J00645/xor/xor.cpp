#include<bits/stdc++.h>
using namespace std;
int n,k,w,a[500009],m,z;
bool f;
struct q{
	int qi,zh,ju;
}v[500009]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			z=a[i];
			for(int l=i+1;l<=j;l++){
				z^=a[l];
			}
			if(z==k){
				f=false;
				for(int l=1;l<=m;l++){
					if((i>=v[l].qi&&j<=v[l].zh)||(i<=v[l].qi&&j<=v[l].zh)||(i>=v[l].qi&&j>=v[l].zh)||(i<=v[l].qi&&j>=v[l].zh)){
						if(v[l].ju<=j-i+1){
							f=true;
							break;
						}
					}
				}
				if(!f){
					m++;
					v[m].qi=i;
					v[m].zh=j;
					v[m].ju=j-i+1;
				}
			}
		}
	}
	cout<<m;
	return 0;
}
