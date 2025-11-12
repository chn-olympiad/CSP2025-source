#include<bits/stdc++.h>
using namespace std;
long long n,q,a[200005][3][4];
string s[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		long long lens=s[i][0].length(),h=0,l=0,r=0;
		for(int j=0;j<lens;j++){
			if(s[i][0][j]=='b'){
				h++;
				a[i][0][0]=j;
			}else{
				if(h==0){
					l++;
				}else{
					r++;
				}
			}
		}
		a[i][0][1]=l;
		a[i][0][2]=r;
		lens=s[i][1].length(),h=0,l=0,r=0;
		for(int j=0;j<lens;j++){
			if(s[i][1][j]=='b'){
				h++;
				a[i][1][0]=j;
			}else{
				if(h==0){
					l++;
				}else{
					r++;
				}
			}
		}
		a[i][1][1]=l;
		a[i][1][2]=r;
	}
	while(q--){
		string t,at;
		cin>>t>>at;
		long long lent=t.length(),h=0,l=0,r=0,cnt=0,w;
		for(int j=0;j<lent;j++){
			if(t[j]=='b'){
				h++;
				w=j;
			}else{
				if(h==0){
					l++;
				}else{
					r++;
				}
			}
		}
		h=0;
		long long alent=t.length(),al=0,ar=0,aw;
		for(int j=0;j<alent;j++){
			if(at[j]=='b'){
				h++;
				aw=j;
			}else{
				if(h==0){
					al++;
				}else{
					ar++;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i][0][1]<=l and a[i][0][2]<=r and a[i][1][1]<=al and a[i][1][2]<=ar and w-aw==a[i][0][0]-a[i][1][0]){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
