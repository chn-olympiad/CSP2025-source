#include<bits/stdc++.h>
using namespace std;
int zhuowei[100][100];
int lzc[10000+100];
bool cmp(int a,int b){
	 return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int c=0;
for(int i=1;i<=n;i++){
 for(int j=1;j<=m;j++){
 	cin>>zhuowei[i][j];
 	lzc[++c]=zhuowei[i][j];
 }	
}

sort(lzc+1,lzc+1+n*m,cmp);
int l=0;

for(int i=1;i<=c;i++){
	
	
	if(lzc[i]==zhuowei[1][1]) {
	l=i;
	break;	
	}
}

if(l%(2*n)==0){

	cout<<l/n<<" "<<(n-l%(2*n))%n;
	
}
else {
	int mod =0;
	if(l%n!=0)mod=1;

if(l%(2*n)<n)cout<<l/n+mod<<" "<<(l%(2*n));	
else 
{
	cout<<cout<<l/n+mod;
	if((l+1)%(2*n))==0)cout<<     l/n+mod<<" "<<(l%(2*n))+1;                                                                                                                                                                                                                                                                      
}
}

	return 0;
}

