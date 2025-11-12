#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;
string s;
int luogu_id[nmax],top;
int main(){
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 ios::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 cin>>s;
 for(int i=0;i<s.size();i++){
  if(isdigit(s[i]))luogu_id[++top]=s[i]-48;
 }
 sort(luogu_id+1,luogu_id+1+top);
 for(int i=top;i;i--){
  cout<<luogu_id[i];
 }
 return 0;
}