#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,q,ls[N],lt1,lt2,ans=0;
string s1[N],s2[N],t1,t2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		
		cin>>s1[i]>>s2[i];
		ls[i]=s1[i].size();
	}	
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		lt1=t1.size();
		lt2=t2.size();
		for(int j=1;j<=n;j++){
			if(ls[i]<lt1 && ls[i]<lt2){
				
			}
		}
		
		cout<<ans<<endl;
	}
		
	
	
	
	return 0;
}
