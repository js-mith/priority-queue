#include<iostream>
using namespace std;
#include "priorityqueue.h"

int main() {
    priorityqueue p;

    p.insert(100);
     p.insert(10);
      p.insert(15);
       p.insert(29);
        p.insert(5);
         p.insert(0);
          p.insert(50);
           p.insert(45);

           cout << p.getsize() << endl;
           cout << p.getmin() << endl;

           while(!p.isempty()){
            cout << p.removemin() << " ";
           }
     
     return 0;
}