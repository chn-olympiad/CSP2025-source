#include <bits/stdc++.h>
using namespace std;
const int MAX=1e3+5;

int t,n,mid,ans,n1,n2,n3;


struct edge{
	int a1,a2,a3,p;
	bool f1,f2,f3;
};
struct ft{
	int e1,e2,m1,m2,mc,mn,nc,mm;
};
bool cmp1(ft a,ft b){
	return a.mc<b.mc;
}
bool cmp2(edge c,edge b){
	return c.a1>b.a1;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	bool f2=0,f3=0;
     ans=0;n1=0;n2=0;n3=0;
    	edge a[MAX];
    	ft b[MAX];
    	cin>>n;
    	mid=n/2;
    	for(int i=1;i<=n;i++) {
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(a[i].a3!=0) f3=1;
		if(a[i].a2!=0) f2=1;
		a[i].p=i;
		int mm=max(max(a[i].a1,a[i].a2),a[i].a3);
		if(mm==a[i].a1){
			b[i].mm=1;
			b[i].e1=mm-a[i].a2;
			b[i].e2=mm-a[i].a3;
			b[i].m1=2;
			b[i].m2=3;
			n1++;
			b[i].mc=min(b[i].e1,b[i].e2);
			b[i].nc=max(b[i].e1,b[i].e2);
			if(b[i].mc==b[i].e1) b[i].mn=b[i].m1;
			else b[i].mn=b[i].m2;
		}
		else if(mm==a[i].a2){
			b[i].mm=2;
			b[i].e1=mm-a[i].a1;
			b[i].e2=mm-a[i].a3;
			b[i].m1=1;
			b[i].m2=3;
			n2++;
			b[i].mc=min(b[i].e1,b[i].e2);
			b[i].nc=max(b[i].e1,b[i].e2);
			if(b[i].mc==b[i].e1) b[i].mn=b[i].m1;
			else b[i].mn=b[i].m2;
		}
		else if(mm==a[i].a3){
			b[i].mm=3;
			b[i].e1=mm-a[i].a1;
			b[i].e2=mm-a[i].a2;
			b[i].m1=1;
			b[i].m2=2;
			n3++;
			b[i].mc=min(b[i].e1,b[i].e2);
			b[i].nc=max(b[i].e1,b[i].e2);
			if(b[i].mc==b[i].e1) b[i].mn=b[i].m1;
			else b[i].mn=b[i].m2;
		}
		ans+=mm;
		}
//        cout<<n1<<" "<<n2<<endl;
//        cout<<ans<<" ";
        if(f3==0&&f2==0){
        	sort(a+1,a+1+n,cmp2);
        	int sum=0;
        	for(int i=1;i<=mid;i++){
        		sum+=a[i].a1;
			}
			cout<<sum<<endl;
		}
        else{

        	sort(b+1,b+1+n,cmp1);
        	if(n1>mid){
        		int i=0;
        		while(1){
                    i++;
        			if(b[i].mm==1){
//        				cout<<b[i].mc<<endl;
        				ans-=b[i].mc;
        				n1--;
					}
					if(n1==mid) break;
				}
			}
			else if(n2>mid){
        		int i=0;
        		while(1){
                    i++;
        			if(b[i].mm==2){

        				ans-=b[i].mc;
        				n2--;
                    }
					if(n2==mid) break;
				}
			}
			else if(n3>mid){
        		int i=0;
        		while(1){
        			i++;
        			if(b[i].mm==3){
        				ans-=b[i].mc;
        				n3--;
					}
					if(n3==mid) break;
				}
			}
       cout<<ans<<endl;
	}
}

	return 0;
}