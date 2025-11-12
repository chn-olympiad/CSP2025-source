#include<bits/stdc++.h>
using namespace std;
long long int n,k,ans;
int a[50005],s[50005];
bool ch(int l,int r){
	for(int i=l;i<=r;i++){
		if(s[i]!=0) return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int l=1;
		int r=l+i;
		while(r<=n){
			if(!ch(l,r)){
				int sum=a[l];
				cout<<l<<" "<<r<<" "; 
				for(int j=l+1;j<=r;j++){
					sum=sum^a[j];
				}
				cout<<"sum:"<<sum<<endl;
				if(sum==k) {
					ans++;
					for(int p=l;p<=r;p++){
						s[p]=1;
					}
				}
			}
			l++;
			r++;
			while(ch(l,r)){
				l++;
				r++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
