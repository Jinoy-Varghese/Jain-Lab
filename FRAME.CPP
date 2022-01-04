#include<math.h>
#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#define FRAM_TXT_SIZ 3
#define MAX_NOF_FRAM 127
using namespace std;
char str[FRAM_TXT_SIZ*MAX_NOF_FRAM];
struct frame
{
    char text[FRAM_TXT_SIZ];
    int seq_no;
}
fr[MAX_NOF_FRAM],shuf_ary[MAX_NOF_FRAM];
int assign_seq_no()
{
    int k=0,i,j;
    for(i=0;i<strlen(str);k++)
    {
	fr[k].seq_no=k;
	for(j=0;j<FRAM_TXT_SIZ&&str[i]!='\0';j++)
	    fr[k].text[j]=str[i++];
    }
    cout<<"\nAfter assigning sequence numbers :\n";
    for(i=0;i<k;i++)
	cout<<i<<fr[i].text;
	return k;
    }
    void generate(int *random_ary,const int limit)
    {
	int r,i=0,j;
	while(i<limit)
	{
	    r=random() % limit;
	    for(j=0;j<i;j++)
		if(random_ary[j]==r)
		    break;
		if(i==j)
		    random_ary[i++]=r;
	    }

	}
    void shuffle(const int no_frames)
    {
	int i,k=0,random_ary[no_frames];
	generate(random_ary,no_frames);
	for(i=0;i<no_frames;i++)
	    shuf_ary[i]=fr[random_ary[i]];
	cout<<"\nAfter shuffling :\n";
	for(i=0;i<no_frames;i++)
	    cout<<shuf_ary[i].seq_no<<shuf_ary[i].text;
    }
    void sort(const int no_frames)
    {
	int i,j,flag=1;
	struct frame hold;
	for(i=0;i<no_frames-1&&flag==1;i++)
	{
	    flag=0;
	    for(j=0;j<no_frames-1-i;j++)
		if(shuf_ary[j].seq_no>shuf_ary[j+1].seq_no)
		{
		    hold=shuf_ary[j];
		    shuf_ary[j]=shuf_ary[j+1];
		    shuf_ary[j+1]=hold;
		    flag=1;
		}
	    }
    }
	int main()
	{
	    int no_frames,i;
	    cout<<"Enter the message : ";
	    fgets(str,sizeof(str),stdin);
	    no_frames=assign_seq_no();
	    shuffle(no_frames);
	    sort(no_frames);
	    cout<<"\n\nAfter Sorting\n";
	    for(i=0;i<no_frames;i++)
		cout<<shuf_ary[i].text;
	    cout<<"\n\n";
	    return 0;
	}





