#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,k;
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;++i){
		int a,b,t;
		cin>>a>>b>>t;
		sum+=t;
	}
	cout<<sum;
 fclose(stdin);
  fclose(stdout);
	return 0;
}
