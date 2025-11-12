#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=1;
    int a[199999]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            continue;
        }
        a[k]=s[i]-'0';
        k++;
    }
    bool f=0;
    sort(a+1,a+k,cmp);
    for(int i=1;i<k;i++){
        if(a[i]==0&&f==0){
            continue;
        }
        cout<<a[i];
        f=1;
    }
    if(f==0){
        cout<<0;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

