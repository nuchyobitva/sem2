#include <iostream>
using namespace std;
struct compl_t {
    compl_t() { 
      real=0.0f;
      imag=0.0f;
    }
    float real;
    float imag;
    istream & read(istream & stream) {
        float n1, n2;
        char a, b, c;
        if (stream >> a && a == '(' && stream >> n1 && stream >> b && b == ',' && stream >> n2 && stream >> c && c == ')') {
            real = n1;
            imag = n2;
        }
        else stream.setstate(ios::failbit);
        return stream;
    }
    ostream & write(ostream & stream)const {
        stream << "(" << real << "," << imag << ")";
        return stream;
    }
    compl_t add( compl_t other)const {
        compl_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
    compl_t sub( compl_t other)const {
        compl_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }
    compl_t mul(compl_t other)const {
        compl_t result;
        result.real = (real * other.real) - (imag * other.imag) ;
        result.imag = (real * other.imag) + (imag * other.real);
        return result;
    }
    compl_t div( compl_t other)const {
        compl_t result;
        result.real = (real * other.real + imag * other.imag) / ((other.real)*(other.real) + (other.imag)*(other.imag));
        result.imag = (imag * other.real - real * other.imag) / ((other.real)*(other.real) + (other.imag)*(other.imag));
        return result;
    }
};
int main() {
    compl_t num1,num2,res;
    char oper;
    if (num1.read(cin)) {
        cin >> oper;
        if (num2.read(cin)) {
            switch (oper) {
                case '+':
                    res = num1.add(num2);
                    res.write(cout);
                    break;
                case '-':
                    res = num1.sub(num2);
                    res.write(cout);

                    break;
                case '*':
                    res = num1.mul(num2);
                    res.write(cout);
                    break;
                case '/':
                    res = num1.div(num2);
                    res.write(cout);
                    break;
            }
        }
     else  cout <<"An error has occured while reading input data";
    }
    else  cout << "An error has occured while reading input data";
    cin.get();
    cin.get();
    return 0;
}
