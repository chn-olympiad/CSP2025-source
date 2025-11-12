#include <iostream>
using namespace std;
const int N=1e3+10;
char c[N];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<m<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
