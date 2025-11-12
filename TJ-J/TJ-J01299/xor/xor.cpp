#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("xor.in",'r',stdin);
    //freopen("xor.out",'w',stdout);
    int n;
    long long k;
    cin>>n>>k;
    //cout<<n^k;
    //return 0;
    vector<long long>a(n+1);
    vector<long long>s(n+1,0);
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)ans++;
        s[i]=(s[i-1]^a[i]);
    }
    int cd=2;
    if(k==0){
    	cout<<ans;
    	return 0;
	}
    while(cd<=n){
       for(int i=cd;i<=n;i++){
       		if(a[i]==0)continue;
       		if(cd==2&&a[i-1]==0)continue;
            if((s[i]^s[i-cd])==k){
                ans++;
                //cout<<i<<' '<<i-cd<<' '<<(s[i]^s[i-cd])<<endl;
            }
       }
       cd++;
    }
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
