#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,q;
string a[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i][0]>>a[i][1];
	while(q--){
		string x,y;
		cin>>x>>y;
		if(x.length()!=y.length())
			cout<<0<<endl;
		else{
			int sum=0;
			int l=0,r=x.length()-1;
			while(l<x.length() && x[l]==y[l]) l++;
			while(r>=0 && x[r]==y[r]) r--;
			string keyw,keyl;
			for(int i=l;i<=r;i++)
				keyw+=x[i],keyl+=y[i];
			for(int i=1;i<=n;i++){
				if(a[i][0].length()<r-l+1)
					continue;
				for(int j=0;j<a[i][0].length();j++){
					bool f=0;
					for(int k=0;k<keyw.length();k++)
						if(a[i][0][j+k]!=keyw[k] || a[i][1][j+k]!=keyl[k]){
							f=1;
							break;
						}
					if(!f){
						sum+=1;
					}	
				}
			}
			cout<<sum<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
