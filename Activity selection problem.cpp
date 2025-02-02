/*You are the event coordinator for your college's tech FST. You have a single auditorium at your disposal, and there are several requests from different clubs to host their events in the auditorium. Each club has provided you with the start time and the end time of their event. Your task is to select the maximum number of events that can be hosted in the auditorium without any time conflicts. Remember, if an event ends at time t, another event can start at the same time t.

Input Format
The first line of input will contain N, the number of events.
Each of the next N lines will contain two integers, the start time and end time of each event.

Output Format
The output should be a single integer, the maximum number of events that can be selected without any overlap*/




#include<iostream>
#include <vector>

using namespace std;

int counter = 1;
struct Activity
{
int startTime, finishTime;
};
void bubbleSort(struct Activity a[], int n)
{
int pass,i; for(pass=1;pass<n;pass++)
{
for(i=0;i<n;i++)
{
if(a[i].finishTime>a[i+1].finishTime)
{
swap(a[i],a[i+1]);
}
}
}
}

void activitySelection(struct Activity a[], int n)
{
int i,j; i=0;
//cout<<a[0].startTime<<" "<<a[0].finishTime<<endl;
counter++;
for(j=i+1;j<n;j++)
{
if(a[j].startTime>=a[i].finishTime)
{
//cout<<a[j].startTime<<" "<<a[j].finishTime<<endl;
counter++;
i=j;
}
}

}

int main()
{
int n,i;

cout<<"Enter Number of Activities: ";
cin>>n;
struct Activity act[n]; for(i=0;i<n;i++)
{
cout<<"Enter start time: ";
cin>>act[i].startTime;
cout<<"Enter finish time: ";
cin>>act[i].finishTime;
}

bubbleSort(act,n);
cout<<"Selected Activities: "<<counter;
activitySelection(act,n);
cout<<"The maximum number of event that can be hosted: "<<counter;
}
