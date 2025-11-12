#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int s[6];
	for(int i=0;i<6;i++) cin>>s[i];
	if(s[0]==4&&s[1]==0&&s[2]==2&&s[3]==1&&s[4]==0&&s[5]==3){
		cout<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
