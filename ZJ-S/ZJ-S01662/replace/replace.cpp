#include<bits/stdc++.h>
using namespace std;



const int maxn=5000005;
int n,q;
string ta,tb,s;
string a[maxn][5];
int ans,sum,num;


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	if(q==1){
		cin>>ta>>tb;s=ta;
		if(ta.size()!=tb.size()){
			cout<<0;
			cout<<'e';
			
		}else{
			cout<<'e';
			for(int i=1;i<=n;i++){
				for(int j=0;j<s.size();j++){
					if(s[j]==a[i][1][j]){
						int op=1;
						for(int k=j+1;k<a[i][1].size();k++){
							if(s[k]!=a[i][1][k])op=0;
						}
						if(op){
							for(int k=j;k<a[i][2].size();k++){
								s[k]=a[i][2][k];
							}
						}
						if(s==tb)ans++;
						s=ta;
					}
				}
			}
		}
		
		
	}
	cout<<ans;
	
	
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/