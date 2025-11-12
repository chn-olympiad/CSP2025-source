#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const int N=1e5+10;

int vis[N];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	
	cin>>n>>q;
	
	for(int i=0;i<n;i++){
		
		string aa,bb;
		
		cin>>aa>>bb;
		
		int l1=aa.size();
		int l2=0,l3=0;
		for(int j=0;j<l1;j++){
			
			if(aa[j]=='b') l2=j;
			if(bb[j]=='b') l3=j; 
			
		} 
		
		vis[abs(l2-l3)]++;
		
	}
	
	while(q--){
		
		string aa,bb;
		
		cin>>aa>>bb;
		
		int l1=aa.size();
		int l2=0,l3=0;
		bool aaa=0,bbb=0;
		for(int j=0;j<l1;j++){
			if(aaa && bbb) break;
			if(aa[j]=='b'){
				
				l2=j;
				aaa=1;
				
			}
			if(bb[j]=='b'){
				l3=j; 
				bbb=1;
			}
			
		}
		
		cout<<vis[abs(l2-l3)]<<endl;
		
	}
	
	return 0;
}

