#include <iostream>

using namespace std;

class Sample{
	int x;
public:
	void set_x(int t){
		this->x = t;
	}
	int get_x(){
		return this->x;
	}
};


class Sample2: public Sample{
    int y;
public:
    void set_y(int t){
        this->y = t;
        this->set_x(t*2);
    }
    int get_y(){
        cout << this->get_x()<< endl;
        return this->y;
    }
};


class Sample3 : public Sample2{
    int z;
public:
    void set_z(int t){
        this->z = t;
        this->set_x(t*2);
    }
    int get_z(){
        cout << this->get_x()<< endl;
        return this->z;
    }
};

int main(){
	Sample s;
	Sample2 s1;
	Sample s3;
	s.set_x(5);
	s1.set_y(10);
	cout << s1.get_y() << endl;
}

