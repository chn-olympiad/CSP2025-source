#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	string s;
	int c[n+5];
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	int r=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') {
		    r=1;
		}
		else {
			break;
		}
	}
	if(r==1){
		printf("%d",n);
		return 0;
    }
    int q=0;
    for(int i=1;i<=n;i++){
		if(s[i]=='0') {
			q++;
		}
		if(q>c[i]){
			q++;
		}
	}
	return 0;
}