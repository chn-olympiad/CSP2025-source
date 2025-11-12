#include<bits/stdc++.h>
using namespace std;
char s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int num=n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			num--;
			cnt++; 
		}
	}
	cout<<(1+num)*num/2+(1+cnt)*cnt/2;
	return 0;
}