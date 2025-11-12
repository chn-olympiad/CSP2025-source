#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005];
string b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int cnt=0;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			string c=a[i],d=b[i];
			for(int j=0;j<c.size();j++){
				int f=1;
				if(c[j]==x[0] && d[j]==y[0]){
					f=0;
					int k=j;
					for(int l=0;l<x.size();l++,k++){
						if(c[k]!=x[l] || d[k]!=y[l]){
							//cout<<l<<" "<<k<<"\n";
							f=2;
							break;
						}
					}
				}
				if(f==0){
					int sum=0,summ=0,fj=0;
					for(int j=0;j<x.size();j++){
						if(x[j]==y[j] && fj==0){
							summ++;
							fj=1;
						} 
						if(x[j]!=y[j] && x[j-1]==y[j-1] && j>0){
							sum++; 
							fj=0;
						} 
					}
					if(sum==1 && summ==2) ans+=2;
					else ans++;
					break;	
				} 
			}
		}
			
		cout<<ans<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
