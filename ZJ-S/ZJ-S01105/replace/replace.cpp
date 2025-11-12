#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[100005],b[100005];
string yuan,gai;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>yuan>>gai;
		int sum=0;
		for(int j=1;j<=n;j++){
			int len=yuan.size();
			if(len-j+1<a[j].size()) break;
			for(int x1=0;x1<len;x1++){
				string g="";
				for(int x2=x1;x2<x1+a[j].size();x2++){
					g=g+yuan[x2];
				}
				if(g==a[j]){
					g=b[j];
					for(int x2=x1-1;x2>=0;x2--){
						g=yuan[x2]+g;
					}
					for(int x2=x1+a[j].size();x2<len;x2++){
						g=g+yuan[x2];
					}
					if(g==gai){
						sum+=1;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
