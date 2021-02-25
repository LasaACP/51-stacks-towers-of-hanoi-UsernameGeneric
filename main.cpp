#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

int y = 0;

void towerOfHanoi(int d, int from, int bar, int other, Stack* tower1,Stack* tower2, Stack* tower3) {
        if(d == 1) {
            cout<< "Moving disk "<<d<< " from "<<from<<" to "<<bar<<endl;
            if (from == 1) {
                if (to == 2) {
                    tower2->push(tower1->pop());
                } else if (to == 3) {
                    tower2->push(tower1->pop());
                }
            } else if (from == 2) {
                if (to == 1) {
                    tower1->push(tower2->pop());
                }
                if (to == 3) {
                    tower3->push(tower2->pop());
                }
            } else if (from == 3) {
                if (to == 2) {
                    tower2->push(tower3->pop());
                }
                if (to == 1) {
                    tower1->push(tower3->pop());
                }
            }
        }
        else{
            towerOfHanoi(d-1, from, other, bar, tower1, tower3, tower2);
            cout<<"Moving disk "<<d<<" from "<<from<<" to "<<bar<<endl;
            if (from == 1) {
                if (bar == 2) {
                    tower2-> push(tower1->pop());
                } else if (bar == 3) {
                    tower2-> push(tower1->pop());
                }
            } else if (from == 2) {
                if (bar == 1) {
                    tower1-> push(tower2->pop());
                }
                if (bar == 3) {
                    tower3-> push(tower2->pop());
                }
            } else if (from == 3) {
                if (bar == 2) {
                    tower2-> push(tower3->pop());
                }
                if (bar == 1) {
                    tower1-> push(tower3->pop());
                }
            }
            towerOfHanoi(d-1, other, bar, from, tower3, tower2, tower1);
        }
}


void toh(int d)
{
    int i, x;
    Disc* a;
    Disc* b;
    Stack* tower1 = new Stack();
    Stack* tower2 = new Stack();
    Stack* tower3 = new Stack();


    for (i = d; i >= 1; i--)
    {
        Disc* d = new Disc(i);
        d->setSize(i);
        tower1->push(d);
    }
    towerOfHanoi(d,1,2,3, tower1, tower2, tower3);
    

}

int main()
{
    int n;
    cout<<"enter the number of disks";
    cin>>n;
    toh(n);
    cout<<y;
    return 0;
}
