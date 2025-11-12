#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[500050],q=0,num=1,cnt=0;
bool flag=1;
int sum;
struct node{
	int l,r;
}s[500050];
bool cmp(node x,node y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	m^=a[i];
    	if(m==k && flag){
    		s[num].l=1;
    		s[num].r=i;
    		flag=0;
		} 
    	if(a[i]==k){
    		num++;
    		s[num].l=i;
    		s[num].r=i;
		}
	}
	m=0;
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			m^=a[j];
			if(m==k){
				num++;
				s[num].l=i;
				s[num].r=j;
				break;
			}
		}
		m=0;
	}
	sort(s+1,s+1+num,cmp);
    int now=1;
    while(now<=num){
    	cnt++;
	    int nn=s[now].r;
	    while(s[now].l<=nn && now<=num) now++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
