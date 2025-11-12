#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100002],SHUN[100003];
string s;
int FN=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		SHUN[i]=i;
	}
    do{
    	int now=0,unpass=0;
    	for(int i=1;i<=n;i++){
    		if(n-unpass<m)break;
    		if(now>=m)break;
    		if(unpass>=arr[SHUN[i]]){
    			unpass++;
    			continue;
			}
			if(s[i-1]=='1')now++;
			else unpass++;
		}
		if(now>=m)FN=(FN+1)%998244353;
	}while(next_permutation(SHUN+1,SHUN+1+n));
	cout<<FN;
	return 0;
}
