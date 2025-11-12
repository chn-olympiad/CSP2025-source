#include<bits/stdc++.h>
using namespace std;
int n,q,m,p,k,l,r;
map<string,int>mp;
string x,y,a,b,h[5000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=5000000;i++)h[i]=h[i/10]+char(48+i%10);
	while(n--){
		cin>>x>>y;
		m=x.size(),p=y.size(),a="",b="";
		for(int i=0;i<min(m,p);i++)if(x[i]!=y[i]){
			k=i;
			break;
		}
		for(int i=m,j=p;i>=0&&j>=0;i--,j--)if(x[i]!=y[j]){
			l=i,r=j;
			break;
		}
		for(int i=k;i<=l;i++)a+=x[i];
		for(int i=k;i<=r;i++)b+=y[i];
		mp[a+b+h[a.size()]]++;
	}
	while(q--){
		cin>>x>>y;
		m=x.size(),p=y.size(),a="",b="";
		for(int i=0;i<min(m,p);i++)if(x[i]!=y[i]){
			k=i;
			break;
		}
		for(int i=m,j=p;i>=0&&j>=0;i--,j--)if(x[i]!=y[j]){
			l=i,r=j;
			break;
		}
		for(int i=k;i<=l;i++)a+=x[i];
		for(int i=k;i<=r;i++)b+=y[i];
		cout<<mp[a+b+h[a.size()]]<<"\n";
	}
}
