#include<bits/stdc++.h>
using namespace std;
int a[1010];
int por(int a,int b){
	int ea[23]={-1};
	int eb[23]={-1};
	int ec[23]={-1};
	int i=0;
	while(a!=1){
		ea[i]=a%2;
		a=a/2;
		i++;
	}
	ea[i]=1;
	
	int j=0;
	while(b!=1){
		eb[j]=b%2;
		b=b/2;
		j++;
	}
	eb[j]=1;
	for(int p=0;p<=max(i,j);p++){
		if(ea[p]==-1){
			ec[p]=eb[p];
			continue;
		}
		if(eb[p]==-1){
			ec[p]=ea[p];
			continue;
		}
		if(ea[p]==eb[p]){
			ec[p]=0;
		}
		else if(ea[p]!=eb[p]){
			ec[p]=1;
		}
		
	}
	int m=0;
	for(int t=0;t<=max(i,j);t++){
		m+=ec[t]*pow(2,t);
	}
	return m;
}
int dfs(int n,int *p,int al,int ans){
	
//	int m=*(p+1);
	
	if(al==0){
		return ans;
		
	}
	else{
		
		for(int i=0;i<al;i++){
			
			if (*(p+i)==n){
				
				ans++;
				int *r=&*(p+i+1);
				al=al-i-1;
				dfs(n,r,al,ans);
				
			}
			else{
				
				if(i==0){
					continue;
				}
				else{
					
					int h;
					
					h=por(*(p+i-1),*(p+i));
					*(p+i)=h;
					int *u=&*(p+i);
					
					dfs(n,u,al--,ans);
				}
			}
		}
		
	}
	
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int w;
	cin>>w;
	for(int i=0;i<w;i++){
		cin>>a[i];
	}
	
	int *q=&a[0];
	
	cout<<dfs(w,q,w,0);
	
	return 0;
}
