#include<fstream>
using namespace std;
ifstream cin("xor.in");
ofstream cout("xor.out");
int n,k,s[10001],sp[10001];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	for(int i=1;i<=n;i++){
     	for(int j=1;j<=n;j++){
	        if(j<i){
	        int sp=0;
	        for(int p;p<=n;p++){
	        	sp=sp^s[p];
			}
			if(sp==k){
				sp++;
				i=j+1;
			}
			}
	    }
    }
    }
    cout<<sp;
	return 0;
}
