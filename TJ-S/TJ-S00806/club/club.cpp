#include <bits/stdc++.h> 
using namespace std;
int t,n,f=0,h=0,m=0,s=0;
string a;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		while (n--){
			cin>>a;
			if (a[0]>a[1] and a[0]>a[2]){
				f+=1;
				s+=a[0];
			}if (a[1]>a[0] and a[1]>a[2]){
				h+=1;
				s+=a[1];
			}if (a[2]>a[1] and a[2]>a[0]){
				m+=1;
				s+=a[2];
			}if (f>n/2 and a[1]>a[2]){
				f-=1;
				h+=1;
				s-=a[0];
				s+=a[1];
			}if (f>n/2 and a[2]>a[1]){
				f-=1;
				m+=1;
				s-=a[0];
				s+=a[2];
			}
			if (h>n/2 and a[0]>a[2]){
				h-=1;
				f+=1;
				s-=a[1];
				s+=a[0];
			}if (h>n/2 and a[2]>a[0]){
				h-=1;
				m+=1;
				s-=a[1];
				s+=a[2];
			}if (m>n/2 and a[1]>a[0]){
				m-=1;
				h+=1;
				s-=a[2];
				s+=a[1];
			}if (m>n/2 and a[0]>a[1]){
				m-=1;
				f+=1;
				s-=a[2];
				s+=a[0];
			}if (f>n/2 and a[2]==a[1]=='0'){
				f-=1;
				s+=a[0];
			}if (h>n/2 and a[0]==a[1]=='0'){
				h-=1;
			    s+=a[1];
			}if (m>n/2 and a[0]==a[2]=='0'){
				m-=1;
				s+=a[2];
			}
			
		}for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				if (a[j]>s){
					s=a[j];
				}
			}
		}
		
	}cout<<s;
	return 0;
}
