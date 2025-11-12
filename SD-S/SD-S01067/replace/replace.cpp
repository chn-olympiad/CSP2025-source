#include<bits/stdc++.h>
using namespace std;
int n,q;
int a,b;
int c,d;
struct Node{
	int k;
	vector<int> a,b;
} st[11451400];
int aa,bb,cc,dd;
int op;
string s;
int ans,len;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
  for(int i=1;i<=n;i++){
  	cin>>s;
  	len=s.size();//cout<<len<<' ';
  	for(int j=1;j<=len;j++)
  		if(s[j-1]=='b'){
  			a=j-1;
  			b=len-j;
  			break;
			}
  	cin>>s;	  
		len=s.size();
		for(int j=1;j<=len;j++)
		  if(s[j-1]=='b'){
		  	c=j-1;
		  	d=len-j;
		  	break;
			}  
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';	
		op=a-c+5e6+10;	
		
		st[op].k++;
		st[op].a.push_back(a);
		st[op].b.push_back(b);	
	}
	
	while(q--){//cout<<9<<'\n';
		ans=0;
		cin>>s;	  
		len=s.size();
		for(int j=1;j<=len;j++)
		  if(s[j-1]=='b'){
		  	aa=j-1;
		  	bb=len-j;
			} 
			
		cin>>s;	  
		len=s.size();
		for(int j=1;j<=len;j++)
		  if(s[j-1]=='b'){
		  	cc=j-1;
		  	dd=len-j;
			} 	 
		op=aa-cc+5e6+10;	
	//	cout<<st[op].k<<' ';
		for(int i=1;i<=st[op].k;i++){
			
			//cout<<st[op].a[i]<<' '<<st[op].b[i]<<' '<<aa<<' '<<bb<<'\n';
			if(st[op].a[i-1]<=aa&&st[op].b[i-1]<=bb)
		    ans++;
		}
		  
		    
		cout<<ans<<'\n';    
	}
	
	return 0;
}
