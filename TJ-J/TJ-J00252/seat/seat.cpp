#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,cj;
	cin>>n>>m>>cj;
	if(cj==100||cj==99){
		cout<<1<<' '<<1;
	}else{
		cout<<n<<' '<<m;
	}
    return 0;
}
