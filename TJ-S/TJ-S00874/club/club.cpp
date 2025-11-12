#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,m=0,b=0,v=0,c=0,s[100000*3];
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
			m++;
			b=max(b,++s[i]);
			c++;
			if(m==3){
				v+=b;
				b==0;
				m==0;
			}
			if(c=n){
			cout<<v<<endl;
			v==0;
			c==0;	
			}
		}
		
	}
	return 0;
} 
