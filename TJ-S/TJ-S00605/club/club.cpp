#include<bits/stdc++.h>
using namespace std;
struct manyi{
	int a,b,c;
}m[100005];
bool cmp(manyi x,manyi y){
	int chax=0;
	if(x.a>=max(x.b,x.c)){
		chax=x.a-max(x.b,x.c); 
	}else if(x.b>=max(x.a,x.c)){
		chax=x.b-max(x.a,x.c); 
	}else if(x.c>=max(x.b,x.a)){
		chax=x.c-max(x.b,x.a); 
	}
	int chay=0;
	if(y.a>=max(y.b,y.c)){
		chay=y.a-max(y.b,y.c); 
	}else if(y.b>=max(y.a,y.c)){
		chay=y.b-max(y.a,y.c); 
	}else if(x.c>=max(x.b,x.a)){
		chay=x.c-max(x.b,x.a); 
	}
	if(chax==chay){
		return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
	}else{
		return chax>chay;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long num=0;
		int bu1=0,bu2=0,bu3=0;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		sort(m+1,m+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(m[i].a>max(m[i].b,m[i].c)){
				bu1++;
				if(bu1<=n/2){
					num+=m[i].a;
				}else{
					m[i].a=0;
					i=i-1;
					bu1--; 
					continue;
				}
			}
			if(m[i].b>max(m[i].a,m[i].c)){
				bu2++;
				if(bu2<=n/2){
					num+=m[i].b;
				}else{
					m[i].b=0;
					i=i-1;
					bu2--;
					continue;
				}
			}
			if(m[i].c>max(m[i].b,m[i].a)){
				bu3++;
				if(bu3<=n/2){
					num+=m[i].c;
				}else{
					m[i].c=0;
					i=i-1;
					bu3--;
					continue;
				}
			}
		}
		cout<<num<<endl;
	}	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
