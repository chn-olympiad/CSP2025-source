#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=0;i<n.size();++i){
		
		if((n[i]>='0')&&(n[i]<='9')){
			++q;
			m[i]=n[i]-48;
			//cout<<n[i];
			//cout<<m[i];
		}
		
	}
	for(int i=0;i<=q;++i){
		for(int j=i;j<=q;++j){
			if(m[i]<m[j]){
				int h=m[i];
				m[i]=m[j];
				m[j]=h;
			}
			
		}
	}
	cout<<0;
	return 0;
}  
