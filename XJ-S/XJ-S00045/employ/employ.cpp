#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int n,m;
string s;
int c[510];
int ulim;


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++){
		scanf("%d",c+i);
	}
	if(n>=31){
		ulim=2147483647;
	}else ulim=pow(2,n);
	
	
	srand(time(0));
	cout<<ulim<<endl;
	cout<<rand()%ulim<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


