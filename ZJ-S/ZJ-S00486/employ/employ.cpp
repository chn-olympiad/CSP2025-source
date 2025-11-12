#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N];
char d[N];
bool fsub1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]=='0')fsub1=true;
	}
	if(!fsub1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	return 0;
}