#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<time.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	srand(time(NULL));
	for(int i=1;i<=m;i++){
		
		cout<<rand()%10<<endl;
	}
	return 0;
}

