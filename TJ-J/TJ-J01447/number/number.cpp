#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1005];
int t,j;
bool bo[1005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<100005;i++){
		cin>>s[i];
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	for(int i=0;i<t;i++){
		bo[i]=true;
	}
	for(int i=0;i<t;i++){
		int maxx=0;
		for(j=0;j<t;j++){
			if(maxx<a[j]&&bo[j]==true){
				maxx=a[j];
			}
		}
		for(j=0;j<t;j++){
			if(a[j]==maxx){
				break;
			}
		}
		bo[j]=false;
		cout<<maxx;
	}
	return 0;
}
