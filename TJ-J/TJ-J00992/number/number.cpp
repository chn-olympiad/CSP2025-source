#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],k=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
    for(long long i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1,cmp);
    for(long long i=1;i<=k;i++){
        cout<<a[i];
    }
    ///A:Hi. My name is A. Nice to meet you.
    ///B:Hello A,my name is B. Nice to meet you too.
    ///A:Do you know NOI?
    ///B:Yes,I know. I'm very love it.
    return 0;
}

