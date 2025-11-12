#include<bits/stdc++.h>
using namespace std;
const int N=8000;
int a[N],mp[N][N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1],sum=0;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
    	if(x==a[i]){
    		sum=i;
		}
	}
	if(sum%m==0){
		if((sum/m)%2==0)
			cout<<sum/m<<' '<<sum%m;
		else{
			cout<<sum/m<<' '<<m-sum%m;
		}
	}
	else{
		if((sum/m)%2==0)
			cout<<sum%m<<' '<<sum/m+1;
		else{
			cout<<m-sum%m<<' '<<sum/m+1;
		}
	}
	///A:Hi. My name is A. Nice to meet you.
    ///B:Hello A,my name is B. Nice to meet you too.
    ///A:Do you know NOI?
    ///B:Yes,I know. I'm very love it.
	return 0;
}

