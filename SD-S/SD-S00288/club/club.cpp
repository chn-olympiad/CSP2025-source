#include<bits/stdc++.h>

using namespace std;

const int N=200001;

int sum=0,ans=0;

int n;

struct node{
	
	int ab=0,ac=0,a=0,b=0,c=0,m=0;
	
}t[N];

bool cmp(node xx,node yy){
	
	
	return xx.m>yy.m;
	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	
	cin>>T;
	
	while(T--){
		
		cin>>n;
		
		sum=0;
		
		int sa=0,sbb=0,sc=0;
		
		for(int i=1;i<=n;i++){
			
			cin>>t[i].a>>t[i].b>>t[i].c;
			
			sa+=t[i].a;
			sbb+=t[i].b;
			sc+=t[i].c;
		}
		
		if(max(sa,max(sbb,sc))==sa){
			
			for(int i=1;i<=n;i++){
				
				t[i].ab=t[i].b-t[i].a;
				t[i].ac=t[i].c-t[i].a;
				t[i].m=max(t[i].ab,t[i].ac);
			}
			
			sum=sa;
			
		}
		else if(max(sa,max(sbb,sc))==sbb){
			
			for(int i=1;i<=n;i++){
				
				t[i].ab=t[i].a-t[i].b;
				t[i].ac=t[i].c-t[i].b;
				t[i].m=max(t[i].ab,t[i].ac);
				
			}
			
			sum=sbb;
			
		}
		else if(max(sa,max(sbb,sc))==sc){
			
			for(int i=1;i<=n;i++){
				
				t[i].ab=t[i].a-t[i].c;
				t[i].ac=t[i].b-t[i].c;
				t[i].m=max(t[i].ab,t[i].ac);
				
			}
			
			sum=sc;
			
		}
		sort(t+1,t+n+1,cmp);
		
		int yu=n;
		
		for(int i=1;i<=n;i++){
			
			if(yu>(n/2) || t[i].m>=0){
				
				sum+=t[i].m;
				yu--;
				
			}
			
		}
		
		cout<<sum<<'\n';
		
	}

	return 0;
}

