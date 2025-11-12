# include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[10100]={0},a[1001000][4],p,cnt=1,sum,mi=INT_MAX;
long long c[10010000],d[10100],e=0;
bool f=false;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(mi>a[i][3]){
				mi=a[i][3];
				p=i;
			}
		}
		a[p][3]=INT_MAX;
		sum+=mi;
		if(b[a[p][2]]!=0){
				for(int i=1;i<=n;i++){
					if(b[i]==b[a[p][1]]){
						b[i]=b[a[p][2]];
					}
					b[a[p][1]]=b[a[p][2]];
				}
			}
		else if(b[a[p][1]]!=0){
			for(int i=1;i<=n;i++){
				if(b[i]==b[a[p][2]]){
					b[i]=b[a[p][1]];
				}
				b[a[p][2]]=b[a[p][1]];
			}
		}
		else{
			b[a[p][1]]=cnt;
			b[a[p][2]]=cnt;
			cnt++;
		}
		while(1){
			f=false;
			mi=INT_MAX;
			for(int i=1;i<=m;i++){
				if(mi>a[i][3]){
					mi=a[i][3];
					p=i;
				}
			}
			sum+=mi;
			a[p][3]=INT_MAX;
			if(b[a[p][2]]!=0){
				if(b[a[p][1]]!=0){
					for(int i=1;i<=n;i++){
						if(b[i]==b[a[p][1]]){
							b[i]=b[a[p][2]];
						}
						b[a[p][1]]=b[a[p][2]];
					}
				}
				else{
					b[a[p][1]]=b[a[p][2]];
				}
			}
			else if(b[a[p][1]]!=0){
				b[a[p][2]]=b[a[p][1]];
			}
			else{
				b[a[p][1]]=cnt;
				b[a[p][2]]=cnt;
				cnt++;
			}
			for(int i=1;i<n;i++){
				if(b[i]!=b[i+1]){
					f=true;
				}
			}
			if(f==false){
				break;
			}
		}	
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>d[j];
			}
			for(int j=1;j<=n;j++){
				if(d[j]==0){
					for(int w=1;w<=n;w++){
						a[m+e][1]=j;
						a[m+e][2]=w;
						a[m+e][3]=d[w];
						e++;
					}
				}
			}
		}
		for(int i=1;i<=m+e;i++){
			if(mi>a[i][3]){
				mi=a[i][3];
				p=i;
			}
		}
		a[p][3]=INT_MAX;
		sum+=mi;
		if(b[a[p][2]]!=0){
				for(int i=1;i<=n;i++){
					if(b[i]==b[a[p][1]]){
						b[i]=b[a[p][2]];
					}
					b[a[p][1]]=b[a[p][2]];
				}
			}
		else if(b[a[p][1]]!=0){
			for(int i=1;i<=n;i++){
				if(b[i]==b[a[p][2]]){
					b[i]=b[a[p][1]];
				}
				b[a[p][2]]=b[a[p][1]];
			}
		}
		else{
			b[a[p][1]]=cnt;
			b[a[p][2]]=cnt;
			cnt++;
		}
		while(1){
			f=false;
			mi=INT_MAX;
			for(int i=1;i<=m+e;i++){
				if(mi>a[i][3]){
					mi=a[i][3];
					p=i;
				}
			}
			sum+=mi;
			a[p][3]=INT_MAX;
			if(b[a[p][2]]!=0){
				if(b[a[p][1]]!=0){
					for(int i=1;i<=n;i++){
						if(b[i]==b[a[p][1]]){
							b[i]=b[a[p][2]];
						}
						b[a[p][1]]=b[a[p][2]];
					}
				}
				else{
					b[a[p][1]]=b[a[p][2]];
				}
			}
			else if(b[a[p][1]]!=0){
				b[a[p][2]]=b[a[p][1]];
			}
			else{
				b[a[p][1]]=cnt;
				b[a[p][2]]=cnt;
				cnt++;
			}
			for(int i=1;i<n;i++){
				if(b[i]!=b[i+1]){
					f=true;
				}
			}
			if(f==false){
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
