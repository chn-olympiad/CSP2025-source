#include <bits/stdc++.h>
using namespace std;
int n,q,l,r;
long long sum;
string s1[200001],s2[200001],as,bs;
bool f;
int len;
int main(){
	freopen("replace.in ","r",stdin);
	freopen("replace.out ","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>as>>bs;
		sum=0;
		l=0,r=as.length()-1;
		while(as[l]==bs[l]){
			l++;
		}
		while(as[r]==bs[r]){
			r--;
		}
		for(int i=1;i<=n;i++){
			if(s1[i].length()<r-l+1){
				continue;
			}
			len=s1[i].length()-1;
			for(int j=0;j<=r;j++){
				f=1;
				for(int k=j;k<j+s1[i].length();k++){
					if(s1[i][k-j]!=as[k]||s2[i][k-j]!=bs[k]){
						f=0;
						break;
					}
				}
				if(f){
					break;
				}
			}
			if(f){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
