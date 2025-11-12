#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
int a[111111][111111];
int m,k;
int sum=0,x1=0,x2=0,x3=0;
int he=0;
bool flag=false;
int k1,k2;
char ch;
bool pan()
{
	if(k1>k2) return true;
	else; 
	    return false;
}
int xuan(int p)
{
	if(p==0) return xuan(int pa);
	if(p==1){
		he++;
		return xuan(int pa);
	}
}
int max(int a,int b,int c){
	if(a>b&&a>c) return a;
	if(b>a&&b>c) return b;
	if(c>a&&c>b) return c;
}
int min(int q,int w,int e)
{
	if(q<w&&q<e) return q;
	if(w<q&&w<e) return w;
	if(e<q&&e<q) return e;
}
void run()
{
    if(k1>k2) cout<<k2;
	else; cout<<k1;	
} 
void go(int x){
    for(int z=1;z<=x;z++){
	    cin>>a[z][1];
	    cin>>a[z][2];
	    cin>>a[z][3];
	    m=max(a[z][1],a[z][2],a[z][3]);
	    k=min(a[z][1],a[z][2],a[z][3]);
	    int s=n/2;
	    if(m==a[z][1]){
	        sum=sum+m;
	        x1++;
	        if(x1==s){
	        	m=max(a[z][2],a[z][3]);
	            if(m==a[z][2]){
	        		sum=sum+m;
	        		x2++;
	        		if(x2==s){
	        			m=a[z][3];
	        			sum=sum+m;
					}
				}
			}
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		go(n);
	}
	run();
	pan();
	int g;
	cin>>g;
	for(int k=1;k<=g;k++){
	    cin>>l;
		xuan(l);	
    }
	int f(0)=0,f(1)=1;
    int f(ms)=f(ms-1)+f(ms-2);
    scanf("%d\n",ch);
    cout<<flag<<endl;
    printf("%d\n",sizeof(flag));
    printf("%d\n",ch);
    printf("%d\n",sizeof(ch));
    printf("%d\n",he);
    printf("%d\n",sizeof(he));
    return 0;
} 

