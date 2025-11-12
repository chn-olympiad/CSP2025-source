#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define INT_MAX LLONG_MAX
const int M=1e6+5;
const int N=1e5+5;
int n,m,k,f[N],ans[15],c[N],index,v[15];
struct line{
	int from,to,value;
}t[M+N*10],ne[N],a[15][N];
int find(int k){
	if(f[k]==k) return k;
	return f[k]=find(f[k]);
}
bool cmp(line x,line y){
	return x.value<y.value;
}
int kruscal(){
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=find(t[i].from),v=find(t[i].to);
		if(u==v) continue;
		cnt++,ans+=t[i].value,f[u]=v;
		ne[cnt].from=t[i].from,ne[cnt].to=t[i].to,ne[cnt].value=t[i].value;
		if(cnt==n-1) return ans;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].from>>t[i].to>>t[i].value;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].value;
			a[i][j].from=i+n;
			a[i][j].to=j;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(t+1,t+1+m,cmp);
	ans[0]=kruscal();
	int minn=INT_MAX,ind;
	for(int i=1;i<=k;i++){
		int sum=ans[0]+v[i],minx=INT_MAX;
		for(int j=1;j<=n-1;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n-1;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[1]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index2=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2) continue;
		int sum=ans[1]+v[i],minx=INT_MAX;
		for(int j=1;j<=n;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[2]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index3=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2||i==index3) continue;
		int sum=ans[2]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+1;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+1;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[3]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index4=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2||i==index3||i==index4) continue;
		int sum=ans[3]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+2;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+2;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[4]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index5=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2||i==index3||i==index4||i==index5) continue;
		int sum=ans[4]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+3;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+3;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[5]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index6=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2||i==index3||i==index4||i==index5||i==index6) continue;
		int sum=ans[5]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+4;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+4;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[6]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index7=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index2||i==index3||i==index4||i==index5||i==index6||i==index7) continue;
		int sum=ans[6]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+5;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+5;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[7]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index8=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index8||i==index2||i==index3||i==index4||i==index5||i==index6||i==index7) continue;
		int sum=ans[7]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+6;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+6;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[8]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index9=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index9||i==index2||i==index3||i==index4||i==index5||i==index6||i==index7||i==index8) continue;
		int sum=ans[8]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+7;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+7;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[9]=minn;
	sort(ne+1,ne+1+m,cmp);
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++) a[i][index+n].value=INT_MAX;
	int index10=index;
	minn=INT_MAX,ind=0,index=0;
	for(int i=1;i<=k;i++){
		if(i==index10||i==index2||i==index3||i==index4||i==index5||i==index6||i==index7||i==index8||i==index9) continue;
		int sum=ans[9]+v[i],minx=INT_MAX;
		for(int j=1;j<=n+8;j++){
			line x;
			if(a[i][ne[j].to].value<a[i][ne[j].from].value) x=a[i][ne[j].to];
			else x=a[i][ne[j].from];
			if(x.value<ne[j].value&&max(a[i][ne[j].to].value,a[i][ne[j].from].value)<=ne[j].value){
				sum=sum-ne[j].value+x.value;
				c[x.to]=1;
			}
		}
		int in;
		for(int j=1;j<=n;j++){
			if(c[a[i][j].to]==0){
				if(a[i][j].value<minx){
					minx=a[i][j].value;
					in=j;
				}
			}
		}
		sum+=minx;
		if(sum<minn){
			minn=sum;
			index=i;
			ind=in;
		}
	}
	for(int j=1;j<=n+8;j++){
		line x;
		if(a[index][ne[j].to].value<a[index][ne[j].from].value) x=a[index][ne[j].to];
		else x=a[index][ne[j].from];
		if(x.value<ne[j].value&&max(a[index][ne[j].to].value,a[index][ne[j].from].value)<=ne[j].value){
			ne[j].from=x.from,ne[j].to=x.to,ne[j].value=x.value;
		}
	}
	ne[++m].from=a[index][ind].from,ne[m].to=a[index][ind].to,ne[m].value=a[index][ind].value;
	ans[10]=minn;
	int lminn=INT_MAX;
	for(int i=0;i<=10;i++){
		lminn=min(lminn,ans[i]);
	}
	cout<<lminn;
	return 0;
}
