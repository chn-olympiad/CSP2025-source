#include<bits/stdc++.h>
#pragma GCC optimize(2,3,4,5,6,7,"Ofast")
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,a[514514],x[514514],s;
vector<int>f1;
map<int,bool>f2;
int main(){
  freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i]=read();
		x[i]=x[i-1]^a[i];
	}
	f1.push_back(0);f2[0]=1;
	for(int i=1;i<=n;i++){
		int f=f1.size();
		if(f2[(k^a[i])]==1){
			s++;f1.clear();f2.clear();f1.push_back(0);f2[0]=1;continue;
		}
		
		for(int j=0;j<f;j++){
			if(f2[(f1[j]^a[i])]==0){f1.push_back(f1[j]^a[i]);f2[f1[j]^a[i]]=1;}
		}
		//for(int j=0;j<f1.size();j++)cout<<f1[j]<<' ';cout<<endl;
	}cout<<s;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
