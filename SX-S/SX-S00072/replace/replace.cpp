#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,r=0;
	scanf("%d %d",&n,&q);
	string s,s1,t,t1;
	for(int i=1;i<=n;i++){
	    cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
        cin>>t[i]>>t1[i];
	}
	for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
        	if(s[j]==t[i]&&s1[j]==t1[i]){
        		r=1;
			}
			else r=0;
	    }
	    if(r=0){
	    	printf("0\n");
		}
	}
	return 0;
}