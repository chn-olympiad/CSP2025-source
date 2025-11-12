#include<bits/stdc++.h>
using namespace std;
const int M=5000000;
int n,q,l1,l2,x,y,c,d,a1,a2,b1,b2;
long long s,s1,s2,ans;
long long gehs(int a,int b){
	s=a+b*M;
	return s;
}
map<long long,long long> a;
string h1,h2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h1>>h2;
		for(int j=0;j<h1.size();j++){
			if(h1[j]=='b'){
				x=j;
				y=h1.size()-j-1;
				break;
			}
		}
		for(int j=0;j<h2.size();j++){
			if(h2[j]=='b'){
				a[gehs(x,y)]=gehs(j,h1.size()-j-1);
				//a[i][1][0]=j;
				//a[i][1][1]=;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>h1>>h2;
		l1=h1.size();
		l2=h2.size();
		if(l1!=l2){
			cout<<0<<endl;
		}else{
			for(int j=0;j<h1.size();j++){
				if(h1[j]=='b'){
					x=j;
					y=h1.size()-j-1;
					break;
				}
			}
			for(int j=0;j<h2.size();j++){
				if(h2[j]=='b'){
					c=j;
					d=h1.size()-j-1;
					break;
				}
			}
			a1=min(x,c);
			a2=min(y,d);
			b1=max(x,c);
			b2=max(d,y);
			for(int p=0;p<=a1;p++){
				for(int k=0;k<=a2;k++){
					s1=gehs(p+b1-a1,a2-k);
					s2=gehs(p,b2-k);
					if(a[s1]==s2 or a[s2]==s1){
						ans++;
					}
				}
			}
			cout<<ans;
			cout<<endl;
		}
	}
	return 0;
}