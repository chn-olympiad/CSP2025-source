#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char s[1000005],a[1000005];
    long long int sum=0,h=0;
    cin>>s;
    long long int n=strlen(s);
    if(n==1){
        cout<<s[0];
    }else{
		for(int i=0;i<n;i++){
			if(s[i]>='0'&&s[i]<='9'){
				sum++;
				a[h]=s[i];
				h++;
			}
		}
		sort(a,a+sum);
		for(int i=sum-1;i>=0;i--){
			cout<<a[i];
		}
    }












	fclose(stdin);
	fclose(stdout);
	return 0;
}
