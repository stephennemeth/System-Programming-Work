#include <string>
#include "Test.h"
using namespace std;

class Test {

private:
    string name;
    int count;
public:
    Test(string name, int count) {
        this->name = name;
        this->count = count;
    }
    void  setName(string name) {
        this->name = name;
    }

    string getName() const{
        return this->name;
    }

    void setCount(int x) {
        this->count = x;
    }

    void increment(int x) {
        this->count += x;
    }

    int getCount() const {
        return this->count;
    }
};


#endif
