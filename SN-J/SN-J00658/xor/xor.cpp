#include <fstream>
using namespace std;
ifstream cin("xor5.in");
ofstream cout("xor.out");
int n,k,a[500001],sr=0;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j)
				continue;
			int cr=0;
			for(int p=i;p<=j;p++){
				cr=cr^a[p];
			}
			if(cr==k){			
				sr++;
				i=j+1;}	
		}
	}
	cout<<sr;
	return 0;
}
