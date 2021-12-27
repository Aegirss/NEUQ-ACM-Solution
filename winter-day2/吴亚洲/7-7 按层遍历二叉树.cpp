#include<bits/stdc++.h>
using namespace std;
int pre[15],mid[15];
struct Node
{
	int date;
	Node* left;
	Node* right;
};
queue<Node>q;
Node* rebuild(int pre[],int mid[],int len)
{
	if(len==0)
	return NULL;
	Node* x=new Node;
	x->date=pre[0];
	int i;
	for(i=0;i<len;i++)
	if(mid[i]==pre[0])
	break;
	x->left=rebuild(pre+1,mid,i);
	x->right=rebuild(pre+i+1,mid+i+1,len-i-1);
	return x;
}
void show(Node t)
{
	q.push(t);
	while(!q.empty())
	{
		cout<<q.front().date<<" ";
		if(q.front().left!=NULL)
		q.push(*q.front().left);
		if(q.front().right!=NULL)
		q.push(*q.front().right);
		q.pop();
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>pre[i];
	for(int i=0;i<n;i++)
	cin>>mid[i];
	Node* t=new Node;
	t=rebuild(pre,mid,n);
	show(*t);
	while(!q.empty())
	{
		int x=q.front().date;
		cout<<x<<" ";
		q.pop();
	}
}
