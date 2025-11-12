#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,g,q=1,w=1,b=1;
	cin>>n>>m;
	int y[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>y[i];
	}
	g=y[1];
	sort(y+1,y+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(y[i]==g){
			cout<<w<<" "<<q;
			break;
		}
		if(q+b>n||q+b<1){
			w++;
			b=-b;
		}else{
			q+=b;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}