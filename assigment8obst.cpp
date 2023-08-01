//ASSIGNMENT 8
#include<iostream>
using namespace std;
#define size 10
class obst
{
int p[size];
int q[size];
int a[size];
int w[size][size];
int r[size][size];
int c[size][size];
int n;
public:
void getdata()
{
int i;
cout<<"\nOptimal binary search\n";
cout<<"\nEnter number of node";
cin>>n;
cout<<"\nEnter data as\n";
for(i=1;i<=n;i++)
{
cout<<"\n a["<<i<<"]";
cin>>a[i];
}
for(i=1;i<=n;i++)
{
cout<<"\n p["<<i<<"]";
cin>>p[i];
}
for(i=0;i<=n;i++)
{
cout<<"\n q["<<i<<"]";
cin>>q[i];
}
}
int minvalue(int i,int j)
{
int m,k;
int mini=32000;
for(m=r[i][j-1];m<=r[i+1][j];m++)
{

if((c[i][m-1]+c[m][j])<mini)
{
mini=c[i][m-1]+c[m][j];
k=m;
}
}
return k;
}
void buildobst()
{

int i,j,k,l,m;
for(i=0;i<n;i++)
{
w[i][i]=q[i];
r[i][i]=c[i][i]=0;
w[i][i+1]=q[i]+q[i+1]+p[i+1];
r[i][i+1]=i+1;

c[i][i+1]=q[i]+q[i+1]+p[i+1];
}
w[n][n]=q[n];
r[n][n]=c[n][n]=0;
for(m=2;m<=n;m++)
{
for(i=0;i<=n-m;i++)
{
j=i+m;
w[i][j]=w[i][j-1]+p[j]+q[j];
k=minvalue(i,j);
c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
r[i][j]=k;
}
}
}
void buildtree()
{
int i,j,k;
int queue[20],front=-1,rear=-1;
cout<<"\nThe optimal binary search tree\n";
cout<<"\nThe root of OBST"<<r[0][n];
cout<<"\nThe cost of OBST"<<c[0][n];
cout<<"\n\n\tNode\tLEFT CHILD\tRIGHT CHILD";
cout<<"\n";
queue[++rear]=0;
queue[++rear]=n;
while(front!=rear)
{

i=queue[++front];
j=queue[++front];
k=r[i][j];
cout<<"\n\t"<<k;
if(r[i][k-1]!=0)
{
cout<<"\t\t"<<r[i][k-1];
queue[++rear]=i;
queue[++rear]=k-1;
}
else
cout<<"\t\tNULL";
if(r[k][j]!=0)
{
cout<<"\t"<<r[k][j];
queue[++rear]=k;
queue[++rear]=j;
}
else
cout<<"\tNULL";

}//end of while

cout<<"\n";
}
};
int main()
{
obst obj;
obj.getdata();
obj.buildobst();
obj.buildtree();

return 0;
}

/*
OUTPUT:
Optimal binary search
Enter number of node4
Enter data as
a[1]1
a[2]2
a[3]3
a[4]4
p[1]3
p[2]3
p[3]1
p[4]1
q[0]2
q[1]3
q[2]1
q[3]1
q[4]1
The optimal binary search tree
The root of OBST2
The cost of OBST32
Node LEFT CHILD RIGHT CHILD
2 1 3
1 NULL NULL
3 NULL 4
4 NULL NULL
*/
