//SN-J00473 曹博皓 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000001],c_c=0,v=1;
signed main(){
	   freopen("number.in","r",stdin);
	   freopen("number.out","w",stdout);
	   cin>>s;
	   int u=s.size();
	   for(int i=0;i<u;i++){
			if('0'<=s[i]&&s[i]<='9'){
				a[v]=s[i]-'0';
				v+=1;
			}
	   }
	   int b=0;
	   for(int i=1;i<=v;i++){
	   		for(int j=v;j>=i+1;j--){
	   			if(a[i]<a[j]){
				    b=a[i];
	   				a[i]=a[j];
	   				c_c=j;
	   				
				}
		    }
		    a[c_c]=b;
	   }
		for(int i=1;i<=v-1;i++){
			cout<<a[i];
		}
	   return 0;
}


