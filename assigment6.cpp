
#include<iostream>
#include <bits/stdc++.h>

using namespace std;
class traversal
{
public:
void create();
void display();
int n;
void BFS();
void DFS();
void DFSVisit(int,bool []);
int vertex=20;
char verOces[20];
char list[20][20];

};
void traversal::create(){

\
for(int i=0;i<vertex;i++){

for(int j=0;j<vertex;j++)
{
list[i][j];
}
}
cout<<"Enter the number of verOces:\n";
cin>>vertex;
for(int i=0;i<vertex;i++){

cout<<"Enter the vertex:";
cin>>verOces[i];
list[i][0]=verOces[i];
}
cout<<"Enter adjancy list:\n";
for(int i=0;i<vertex;i++){
cout<<"For vertex "<<verOces[i]<<" enter the number of connected verOces:";
cin>>n;
for(int j=0;j<n;j++)
{
cout<<"Enter "<<j+1 <<" connected vertex\n";
cin>>list[i][j+1];
}
cout<<"Connected vertex:\n";
for(int j=0;j<n;j++)
{

cout<< list[i][j+1]<<"\t";

}
cout<<endl;
}
}

void traversal::display(){
cout<<"Adjancy list:";
for(int i=0;i<vertex;i++){
cout<<endl;
for(int j=0;j<vertex;j++)
{

cout<<list[i][j]<<"\t";
}
}
}
void traversal::BFS() {
cout<<endl<<"BFS Sequence:";
int visited[vertex] = {0};
queue<int> q;
int start = 0;
q.push(start);
visited[start] = 1;
while (!q.empty()) {
int current = q.front();
q.pop();
cout << verOces[current] << " ";
for (int i = 1; i < vertex; i++) {
if (list[current][i] != '\0' && visited[i] == 0) {
q.push(i);
visited[i] = 1;
}
}
}
}
void traversal::DFSVisit(int v, bool visited[]) {
cout<<endl;
visited[v] = true;
cout << verOces[v] << " ";
for (int i = 1; i < vertex; i++) {
if (list[v][i] != '\0' && !visited[i]) {
DFSVisit(i, visited);
}

}
}
void traversal::DFS() {
cout<<endl<<"DFS Sequence:";
bool *visited = new bool[vertex];
for (int i = 0; i < vertex; i++) {
visited[i] = false;
}
for (int i = 0; i < vertex; i++) {
if (visited[i] == false) {
DFSVisit(i, visited);
}
}
}
int main()
{
traversal t1;
t1.create();
t1.display();
t1.BFS();
t1.DFS();
return 0;
}
/*Graph :taken for Example: A
/|\
B C D
| |
E F
OUTPUT:
Enter the number of verOces:
6

Enter the vertex:a
Enter the vertex:b
Enter the vertex:c
Enter the vertex:d
Enter the vertex:e
Enter the vertex:f
Enter adjancy list:
For vertex a enter the number of connected verOces:3
Enter 1 connected vertex
c
Enter 2 connected vertex
d
Enter 3 connected vertex
b
Connected vertex:
c d b
For vertex b enter the number of connected verOces:1
Enter 1 connected vertex
a
Connected vertex:
a
For vertex c enter the number of connected verOces:2
Enter 1 connected vertex
a
Enter 2 connected vertex
e
Connected vertex:
a e
For vertex d enter the number of connected verOces:2
Enter 1 connected vertex
a

Enter 2 connected vertex
f
Connected vertex:
a f
For vertex e enter the number of connected verOces:1
Enter 1 connected vertex
c
Connected vertex:
c
For vertex f enter the number of connected verOces:1
Enter 1 connected vertex
d
Connected vertex:
d
Adjancy list:
a c d b + ¥//symbols are garbage value
b a H
c a e + v
d a f ?
e c e ?
f d @
BFS Sequence:a b c d e f
DFS Sequence:
a
b
c
e
f
d
*/
