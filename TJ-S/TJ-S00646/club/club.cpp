#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],d[150005],e[150005];
long long sum1,sum2,sum3;
long long ans;
long long x=1,num,p=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		num=n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
	    }
	    sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        sort(c+1,c+1+n);
    }
    for(int i=1;i<=n/2;i++){
    	d[x]=a[num];
    	x++;
    	num--;
	}
	x--;
	num++;
	for(int i=1;i<=n/2;i++){
    	d[x]=b[num];
    	x++;
    	num--;
	}
	x--;
	num++;
	for(int i=1;i<=n/2;i++){
    	d[x]=c[num];
    	x++;
    	num--;
	}
	x--;
	sort(d+1,d+1+x);
	for(int i=x;i>=n;i--){
		ans+=d[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//分给你了，我不要了┗( ′?∧?｀)┛ 
//TwT 
