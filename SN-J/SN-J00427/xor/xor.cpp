//SN-J00427 强立琨 西安市交大附中浐灞右岸学校 
#include<bits/stdc++.h>
using namespace std;
unsigned int ans,k,n,x,m,l,r,st;
int a[500010],b[500010],c[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		if(a[i]==k){
			ans++;
			b[i]=i;
		}
	}
	st=1;
	for(int i=1;i<=n;i++){
		r=i+st;
		l=st;
		while(b[l]!=0 || b[r]!=0){
			if(b[r]!=0){
				st=b[r]+1;
				l=st;
				r=i+st;
			}
			if(b[l]!=0){
				st=b[l]+1;
				l=st;
				r=i+st;
			}
		}
		while(r<=n){
			while(b[l]!=0 || b[r]!=0){
				if(b[r]!=0){
					l=b[r]+1;
					r=i+l;
				}
				if(b[l]!=0){
					l=b[l]+1;
					r=i+l;
				}
			}
			if(r>n){
				continue;
			}
			x=c[r]^c[l-1];
			if(x==k){
				int flag=0;
				for(int j=l;j<=r;j++){
					if(b[j]!=0){
						flag=1;
						break;
					} 
				}
				if(flag==1){
					break;
				}
				ans++;
				for(int j=l;j<=r;j++){
					b[j]=r;
				} 
				l=r+1;
				r=l+i;
				continue;
			} 
			l++;
			r++;
		}
	}
	cout<<ans ;
	return 0;
}
