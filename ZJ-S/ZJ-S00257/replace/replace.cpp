#include <bits/stdc++.h>
using namespace std;
unordered_map<string,string>z1;
int n,q,ans,le1,le2;
string a,b,n1,n2,n3;
bitset<5000010>pd1,pd2; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	double c=clock();
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		z1[a]=b;
	}
	for(int i=1;i<=q;++i){
		ans=0;
		n1.clear(),n2.clear();
		cin>>a>>b;
		le1=a.size(),le2=b.size();
		if(le1!=le2){
			cout<<0<<'\n';
			continue;
		}
		pd1[le1]=1;
		for(int i=le1-1;i;--i){
			pd1[i]=((a[i]==b[i])&&(pd1[i+1]))?1:0;
		}
		pd2[0]=(a[0]==b[0])?1:0;
		for(int i=1;i<le1;++i){
			pd2[i]=((a[i]==b[i])&&(pd2[i-1]))?1:0;
		}
		for(int i=0;i<le1;++i){
			n1.clear(),n2.clear();
			for(int j=i;j<le1;++j){
				n1.push_back(a[j]);
				n2.push_back(b[j]);
				if(z1[n1]==n2&&pd1[j+1]){
					if(i==0){
						++ans;
					}
					else if(pd2[i-1]){
						++ans;
					}
				}
				if((double)clock()-c>600.0) break;
			}
			if((double)clock()-c>600.0) break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

