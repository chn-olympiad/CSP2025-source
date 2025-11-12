#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n;
bool trinumber(int a,int b,int c){
	if(a<(b+c)&&b<(a+c)&&c<(a+b)){
		return 1;
	}else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(trinumber(a,b,c))cout<<1;
	else cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}